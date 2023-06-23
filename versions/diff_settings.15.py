#!/usr/bin/env python3

def apply(config, args):
    config['mapfile'] = 'versions/15/build/turok3.15.map'
    config['myimg'] = 'versions/15/build/turok3.15.z64'
    config['baseimg'] = 'versions/baserom.15.z64'
    config['source_directories'] = ['src/15', 'src/common', 'include', 'versions/15/asm']
