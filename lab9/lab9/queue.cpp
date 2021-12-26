#include "Header.h"

Queue::Queue()
{
    head = tail = NULL;
}

Queue::Queue(const Queue& other)
{
    if (other.head == NULL)
    {
        head = tail = NULL;
        return;
    }
    Element* temp = other.head;
    while (temp != other.tail)
    {
        this->push(temp->number);
        temp = temp->prev;
    }
    this->push(temp->number);
}

Queue::Queue(Queue&& other)noexcept
{
    if (other.head == NULL)
    {
        head = tail = NULL;
        return;
    }
    head = other.head;
    tail = other.tail;
    other.head = other.tail = NULL;
}

Queue::~Queue()
{
    if (head == NULL) return;
    while (this->get_size() > 0)
    {
        this->pop();
    }
    head = tail = NULL;
}

void Queue::push(int element)
{
    Element* temp = new Element;
    temp->number = element;
    if (head != NULL)
    {
        temp->next = tail;
        temp->prev = head;
        tail->prev = temp;
        head->next = temp;
        tail = temp;
    }
    else temp->next = temp->prev = head = tail = temp;
}

int Queue::pop()
{
    if (head == tail)
    {
        if (head == NULL) return 0;
        int res = head->number;
        delete head;
        head = tail = NULL;
        return res;
    }
    int res = head->number;
    head = head->prev;
    delete head->next;
    head->next = tail;
    tail->prev = head;
    return res;
}

int Queue::peek()
{
    if (head == NULL) return 0;
    return head->number;
}

int Queue::get_size()
{
    int i = 0;
    Element* temp = tail;
    if (head == NULL) return 0;
    while (temp != head)
    {
        i++;
        temp = temp->next;
    }
    return i + 1;
}

Queue& Queue::operator=(const Queue& other)
{
    if (this == &other || other.head == NULL) return *this;
    Element* temp = other.head;
    while (temp != other.tail)
    {
        this->push(temp->number);
        temp = temp->prev;
    }
    this->push(temp->number);
    return *this;
}

Queue& Queue::operator=(Queue&& other)noexcept
{
    if (this == &other || other.head == NULL) return *this;
    head = other.head;
    tail = other.tail;
    other.head = other.tail = NULL;
    return *this;
}