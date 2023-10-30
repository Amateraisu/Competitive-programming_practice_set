#include <bits/stdc++.h>

struct Block {
    int data;
    int size;
    Block* next;
    bool used;

};

Block* heapStart = nullptr;
Block* top= nullptr;

size_t alignment = alignof(std::max_align_t);

inline auto align(size_t n) -> size_t {
    return (n + (alignment - 1)) & ~(alignment - 1);
}

auto requestMemoryFromOS(size_t n) -> Block* {
    // request from here
    auto block = reinterpret_cast<Block*>(sbrk(0));
    if (sbrk(n) == (void*)-1) return nullptr;

    return block;
}

auto alloc(size_t n) -> Block* {
    // if cannot find here
    n = align(n);

    Block* block = requestMemoryFromOS(n);

    // stack up chains here
    // init heapstart
    if (heapStart == nullptr) {
        heapStart = block;
    }
    if (top != nullptr) {
        top->next = block;
    }
    top = block;
    return block;
}




