# -*- coding: utf-8 -*-
# file: cn_text_deduplication.py
# date: 2022-01-22


import os
import sys

CURR_DIR: str = os.path.abspath(
    os.path.dirname(__file__))

import stanza
import pyosimhash
from typing import List, Tuple
from stanza.server import CoreNLPClient
from stanza.protobuf.CoreNLP_pb2 import Document 
from lib import utils


if __name__ == "__main__":
    utils.init_corenlp("./_corenlp")
    corenlp_client: CoreNLPClient = utils.get_corenlp_client()

    text_path: str = os.path.join(CURR_DIR, "..", "texts")
    path: str = os.path.join(
        CURR_DIR, "..", "texts", "zh1.txt")
    zh_text_files: List[str] = utils.get_files(text_path, "zh")

    print("Finished initialized CoreNLP Client")
    
    for text_file in zh_text_files:
        text: str = utils.file2text(text_file)
        text_ana: Document = corenlp_client.annotate(text)
        for i, sent in enumerate(text_ana.sentence):
            splitted_sent: List[Tuple[str, str] ] = []
            for j, token in enumerate(sent.token):
                splitted_sent.append((token.word, token.pos))
            #print(splitted_sent)

        keywords = utils.corenlp_doc2keywords(text_ana, 8)
        print(keywords)
