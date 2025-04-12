#include "todo.h"
#include <stdexcept>

void TodoList::init() {
    size = 0;
    for(int i = 0; i < MAX_TASKS; i++) { 
    tasks[i] = nullptr;
 }
    // TODO: set size to 0 and all task pointers to nullptr
}

void TodoList::destroy() {
    for(int i = 0; i < size; i++) { 
        delete[] tasks[i];
        tasks[i] = nullptr; 
    }
         size = 0;
    // TODO: delete all tasks and reset pointers
}

int TodoList::string_length(const char* str) const {
    int len = 0;
    int i = 0;
    while(str[i] != '\0'){
        i++;
        len++;
    }
    // TODO: return the number of characters before '\0'
    return len;
}

void TodoList::string_copy(char* dest, const char* src) const {
    // TODO: copy characters from src to dest
    int len = string_length(src);
    for(int i = 0; i<len;i++){
        dest[i] = src[i];
    }
    dest[len] = '\0';

}

void TodoList::add_task(const char* task) {
    if (size >= MAX_TASKS) {
        throw std::overflow_error("full.");
    }
    if (task != nullptr) {
        int len = string_length(task);
        tasks[size] = new char[len + 1];
        string_copy(tasks[size], task);
        size++;
    }
    // TODO: if full, throw. otherwise allocate and copy new task
}

void TodoList::remove_task(int index) {
    // TODO: check bounds, delete task, shift left
    if (index < 0 || index >= size) {
        throw std::out_of_range("invalid index.");
    }

    delete[] tasks[index];
    for (int i = index; i < size - 1; ++i) {
        tasks[i] = tasks[i + 1];
    }
    tasks[size - 1] = nullptr;
    size--; 
}

const char** TodoList::get_pending_tasks(int& count) const {
    // TODO: set count and return task array
    const char** pendingTasks = new const char*[size];
    for (int i = 0; i < size; ++i) {
        pendingTasks[i] = tasks[i];
    }
    count = size;
    return pendingTasks;
}