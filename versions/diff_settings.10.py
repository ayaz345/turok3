#!/usr/bin/env python3

def apply(config, args):
    config['mapfile'] = 'versions/10/build/turok3.10.map'
    config['myimg'] = 'versions/10/build/turok3.10.z64'
    config['baseimg'] = 'versions/baserom.10.z64'
    config['source_directories'] = ['src/10', 'src/common', 'include', 'versions/10/asm']
