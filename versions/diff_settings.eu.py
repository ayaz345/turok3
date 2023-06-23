#!/usr/bin/env python3

def apply(config, args):
    config['mapfile'] = 'versions/eu/build/turok3.eu.map'
    config['myimg'] = 'versions/eu/build/turok3.eu.z64'
    config['baseimg'] = 'versions/baserom.eu.z64'
    config['source_directories'] = ['src/eu', 'src/common', 'include', 'versions/eu/asm']
