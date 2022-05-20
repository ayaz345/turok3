#ifndef CACHE_H
#define CACHE_H

#include "mutex.h"
#include "list.h"
#include "common.h"

#define CACHE_ENTRIES (1024)
#define CACHE_QUEUE_SIZE (64)

enum {
    MEMENTRY_FLAG_UNALLOCATED = 0,
    MEMENTRY_FLAG_LOCKED = (1 << 8),
    MEMENTRY_FLAG_DLISTA_LOCKED = (1 << 9),
    MEMENTRY_FLAG_DLISTB_LOCKED = (1 << 10),
    MEMENTRY_FLAG_ALLOCATED = (1 << 11)
};

enum {
    CACHEENTRY_FLAG_UNALLOCATED = 0,
    CACHEENTRY_FLAG_ALLOCATED = (1 << 0)
};


typedef struct CMemEntry {
    /* 0x00 */ void* data; // "pData"
    /* 0x04 */ int32_t size; // "Size"
    /* 0x08 */ uint32_t flags; // "dwFlags"
    /* 0x0C */ uint32_t age; // "Age"
    /* 0x10 */ struct CCacheEntry* cacheEntry; // "pCacheEntry"
    /* 0x14 */ struct CMemEntry* last; // "pLast"
    /* 0x18 */ struct CMemEntry* next; // "pNext"
} CMemEntry; /* sizeof = 0x1C */

typedef void (*DecompressionCallback)(void* notifyId, struct CCacheEntry* cacheEntry);

typedef struct CCacheEntry {
    /* 0x00 */ CMemEntry* memEntry; // "pMemEntry"
    /* 0x04 */ CMemEntry* referencedMemEntry; // "pReferencedMemEntry"
    /* 0x08 */ void* requestId; // "pRequestID"
    /* 0x0C */ int32_t requestLength; // "RequestLength"
    /* 0x10 */ uint32_t flags; // "dwFlags"
    /* 0x14 */ DecompressionCallback decompressCallback; // "DecompressCallback"
    /* 0x18 */ void* notifyId; // "pNotifyID"
    /* 0x1C */ uint32_t memFlags; // "dwMemFlags"
    /* 0x20 */ OSMesgQueue* decompressReplyQueue; // "pDecompressReplyQueue"
    /* 0x24 */ struct CCacheEntry* next; // "pNext"
    /* 0x28 */ struct CCacheEntry* last; // "pLast"
} CCacheEntry; /* sizeof = 0x2C */ // "CCacheNtry2"

typedef struct {
    /* 0x000 */ CMemEntry* memEntries; // "MemEntries"
    /* 0x004 */ CMemEntry** memEntriesFree; // "FreeEntries"
    /* 0x008 */ CMemEntry* currentCompressPos; // "pCurrentCompressPos"
    /* 0x00C */ CCacheEntry* cacheEntries; // "CacheEntries"
    /* 0x010 */ CList memAgeList; // "MemAgeList"
    /* 0x024 */ int32_t dlistValid[2]; // "DListValid"
    /* 0x02C */ int32_t dlistBlocking[2]; // "DListBlocking"
    /* 0x034 */ int32_t currentDlist; // "CurrentDisplayList"
    /* 0x038 */ OSThread thread; // "Thread"
    /* 0x1E8 */ uint8_t unk_0x1E8[0x80];
    /* 0x268 */ OSMesgQueue queue; // "Queue"
    /* 0x280 */ OSMesg messages[CACHE_QUEUE_SIZE]; // "Msgs"
    /* 0x380 */ uint8_t stack[STACKSIZE_CACHE]; // "Stack"
    /* 0xB80 */ CList cacheFreeList; // "CacheFreeList"
    /* 0xB94 */ CList cacheUsedList; // "CacheUsedList"
    /* 0xBA8 */ CList cachePendingList; // "CachePendingList"
    /* 0xBBC */ uint32_t dlistCount[2]; // "MemDListCount"
    /* 0xBC4 */ uint32_t freeEntryCount; // "nFreeEntries"
    /* 0xBC8 */ CMutex mutex; // "Mutex"
    /* 0xBE8 */ CBlocker blocker; // "Blocker"
    /* 0xC04 */ int32_t synchronous; // "bSynchronous"
    /* 0xC08 */ uint32_t ageCount; // "AgeCount"
    /* 0xC0C */ uint32_t unk_0xC0C;
    /* 0xC10 */ int32_t lowRamCount; // "LowRamCount"
} CCache; /* sizeof = 0xC1C */


extern uint32_t gCacheEntryCount;
extern CCache gCache;


extern void CCache__Construct(OSId threadId);
extern void CCache__Main(void*);
extern void CCache__Advance(void);
extern CMemEntry* CCache__LoadPersistantIndex(CISet** dest, void* romAddress, char* description);
extern CMemEntry* CCache__LoadPersistantSubBlock(CISet* sourceIndex, int32_t blockIndex, void* romAddressBase, void* notifyID, DecompressionCallback decompressCallback, char* description);
extern int32_t CCache_GetFromLookupTable(int32_t offset);
extern void CCache__Construct(OSId threadId);

#endif

