#!/usr/bin/env python3

def apply(config, args):
    config['mapfile'] = 'versions/us/build/turok3.us.map'
    config['myimg'] = 'versions/us/build/turok3.us.z64'
    config['baseimg'] = 'versions/baserom.us.z64'
    config['source_directories'] = ['src/us', 'src/common', 'include', 'versions/us/asm']
