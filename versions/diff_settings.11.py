#!/usr/bin/env python3

def apply(config, args):
    config['mapfile'] = 'versions/11/build/turok3.11.map'
    config['myimg'] = 'versions/11/build/turok3.11.z64'
    config['baseimg'] = 'versions/baserom.11.z64'
    config['source_directories'] = ['src/11', 'src/common', 'include', 'versions/11/asm']
