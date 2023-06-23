#!/usr/bin/env python3

def apply(config, args):
    config['mapfile'] = 'versions/3-5-2000/build/turok3.3-5-2000.map'
    config['myimg'] = 'versions/3-5-2000/build/turok3.3-5-2000.z64'
    config['baseimg'] = 'versions/baserom.3-5-2000.z64'
    config['source_directories'] = ['src/3-5-2000', 'src/common', 'include', 'versions/3-5-2000/asm']
