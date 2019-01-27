#ifndef WAVE_H
#define WAVE_H

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <vector>

#define GROUND 127.0
#define MAXPLUS 255.0
#define MAXMINUS 0.0

typedef struct
{
    int fs;
    // 標本化周波数
    int bits;
    // 量子化制度
    int length;
    // データ長
    std::vector<unsigned char> s;
    // 音データ
} MONO_PCM;
// モノラルの音声データの定義

typedef struct
{
    char chunkID[4];
    long chunkSize;
    char chunkFormType[4];
} RIFF_CHUNK;
// RIFFチャンクの定義

typedef struct
{
    char chunkID[4];
    long chunkSize;
    short waveFormatType;
    short formatChannel;
    long samplesPerSec;
    long bytesPerSec;
    short blockSize;
    short bitsPerSample;
} FMT_CHUNK;
// fmtチャンクの定義

typedef struct
{
    char chunkID[4];
    long chunkSize;
    short data;
} DATA_CHUNK;
// dataチャンクの定義

typedef struct
{
    RIFF_CHUNK riffChunk;
    FMT_CHUNK fmtChunk;
    DATA_CHUNK dataChunk;
} WAVE_FORMAT;
// WAVEフォーマット

void monoWaveRead(MONO_PCM *pcm, char *fileName);
// モノラルの音声データ(waveファイル)の読み込み

void monoWaveWrite(MONO_PCM *pcm, char *fileName);
// モノラルの音声データ(waveファイル)書き込み

#endif