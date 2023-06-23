#!/usr/bin/env python3

def apply(config, args):
    config['mapfile'] = 'versions/18/build/turok3.18.map'
    config['myimg'] = 'versions/18/build/turok3.18.z64'
    config['baseimg'] = 'versions/baserom.18.z64'
    config['source_directories'] = ['src/18', 'src/common', 'include', 'versions/18/asm']
