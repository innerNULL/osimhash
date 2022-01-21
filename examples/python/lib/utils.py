# -*- coding: utf-8 -*-
# file: utils.py
# date: 2022-01-24


import os
import stanza
from typing import List, Tuple, Dict
from stanza.server import CoreNLPClient
from stanza.protobuf.CoreNLP_pb2 import Document


def get_files(
    directory: str, lang: str="zh"
) -> List[str]:
    files: List[str] = []
    for _file in os.listdir(directory):
        if lang in _file.split("_")[0] \
                and ".un~" not in _file:
            files.append(os.path.join(directory, _file))
    return files


def file2text(path: str) -> str:
    return open(path, "r")\
            .read()\
            .strip("\n")\
            .strip(" ")


def register_corenlp_path(corenlp_root: str) -> None:
    corenlp_root = os.path.abspath(corenlp_root)
    os.environ['CORENLP_HOME'] = corenlp_root


def init_corenlp(target_dir: str) -> None:
    corenlp_root: str = os.path.abspath(target_dir)
    stanza.install_corenlp(corenlp_root)
    stanza.download_corenlp_models(
        model='chinese', version='4.4.0', 
        dir=corenlp_root, force=False)

    register_corenlp_path(corenlp_root)


def get_corenlp_client(
        preload: bool=True, be_quiet: bool=True
) -> CoreNLPClient:
    #annotators=['tokenize','ssplit','pos','lemma','ner', 'parse', 'depparse','coref']
    annotators=['tokenize','ssplit', 'pos']
    corenlp_client: CoreNLPClient = CoreNLPClient(
        annotators=annotators, 
        timeout=30000, memory='6G', properties="zh", be_quiet=be_quiet)

    if preload:
        corenlp_client.annotate("")
    return corenlp_client


def pos2keywords(
        pos: List[Tuple[str, str] ]
) -> Dict[str, float]:
    keywords: Dict[str, float] = {}
    for item in pos:
        word: str = item[0]
        pos: str = item[1]
        if pos == "NN":
            if word in keywords:
                keywords[word] += 1
            else:
                keywords[word] = 1
    return keywords


def corenlp_doc2keywords(
        doc: Document, top_k: int=-1, 
        target_pos: List[str] = ["NR", "NN"], 
        norm: bool=True, 
        scale: float=100.0
) -> Tuple[str, float]:
    keywords: Dict[str, float] = {}
    for sent in doc.sentence:
        for token in sent.token:
            word: str = token.word
            pos: str = token.pos
            if pos in target_pos:
                if word in keywords:
                    keywords[word] += 1
                else:
                    keywords[word] = 1
    keywords_: Tuple[str, float] = keywords.items()
    keywords_ = sorted(keywords_, key=lambda x: x[1], reverse=True)
    
    if top_k <= 0:
        top_k = len(keywords_)
    keywords_ = keywords_[:top_k]

    if norm:
        denominator: float = sum([x[1] for x in keywords_])
        keywords_ = [
                (x[0], round(scale * x[1] / denominator, 4)) 
                for x in keywords_]
    return keywords_
