#!/bin/bash
g++ ../graphs.cpp -o drunk `pkg-config --cflags --libs gtk+-2.0`
