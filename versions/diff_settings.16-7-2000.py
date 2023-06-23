#!/usr/bin/env python3

def apply(config, args):
    config['mapfile'] = 'versions/16-7-2000/build/turok3.16-7-2000.map'
    config['myimg'] = 'versions/16-7-2000/build/turok3.16-7-2000.z64'
    config['baseimg'] = 'versions/baserom.16-7-2000.z64'
    config['source_directories'] = ['src/16-7-2000', 'src/common', 'include', 'versions/16-7-2000/asm']
