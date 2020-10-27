#include "LinkedList.h"

LinkedList::Node::Node()
{
	next = nullptr;
	prev = nullptr;
	value = {0};
}

LinkedList::Node::Node(value_type inputValue)
{
	next = nullptr;
	prev = nullptr;
	value = inputValue;
}

LinkedList::Node::Node(Node* inputPrev, Node* inputNext, value_type inputValue)
{
	next = inputNext;
	prev = inputPrev;
	value = inputValue;
}

LinkedList::iterator::iterator()
{
	currentNode = nullptr;
}

LinkedList::iterator& LinkedList::iterator::operator=(const iterator& other)
{
	currentNode = other.currentNode;
	return *this;
}

bool LinkedList::iterator::operator!=(const iterator& other) const
{
	return currentNode != other.currentNode;
}

bool LinkedList::iterator::operator==(const iterator& other) const
{
	return currentNode == other.currentNode;
}

value_type& LinkedList::iterator::operator*()
{
	return currentNode->value;
}

value_type* LinkedList::iterator::operator->()
{
	return &(currentNode->value);
}

LinkedList::iterator& LinkedList::iterator::operator++()
{
	currentNode = currentNode->next;
	return *this;
}

LinkedList::iterator LinkedList::iterator::operator++(int)
{
	iterator lastIterator = *this;
	++(*this);
	return lastIterator;
}

LinkedList::iterator& LinkedList::iterator::operator--()
{
	currentNode = currentNode->prev;
	return *this;
}

LinkedList::iterator LinkedList::iterator::operator--(int)
{
	iterator nextIterator = *this;
	--(*this);
	return nextIterator;
}

LinkedList::const_iterator::const_iterator()
{
	currentNode = nullptr;
}

LinkedList::const_iterator& LinkedList::const_iterator::operator=(const const_iterator& other)
{
	currentNode = other.currentNode;
	return *this;
}

bool LinkedList::const_iterator::operator!=(const const_iterator& other) const
{
	return currentNode != other.currentNode;
}

bool LinkedList::const_iterator::operator==(const const_iterator& other) const
{
	return currentNode == other.currentNode;
}

const value_type& LinkedList::const_iterator::operator*() const
{
	return currentNode->value;
}

const value_type* LinkedList::const_iterator::operator->() const
{
	return &(currentNode->value);
}

LinkedList::const_iterator& LinkedList::const_iterator::operator++()
{
	currentNode = currentNode->next;
	return *this;
}

LinkedList::const_iterator LinkedList::const_iterator::operator++(int)
{
	const_iterator lastNode = *this;
	++(*this);
	return lastNode;
}

LinkedList::const_iterator& LinkedList::const_iterator::operator--()
{
	currentNode = currentNode->prev;
	return *this;
}

LinkedList::const_iterator LinkedList::const_iterator::operator--(int)
{
	const_iterator nextNode = *this;
	--(*this);
	return nextNode;
}

LinkedList::LinkedList()
{
	len = 0;
	head.next = &head;
	head.prev = &head;
}

LinkedList::LinkedList(const LinkedList& other) : LinkedList()
{
	for (const_iterator iteratorForSourceList = other.cbegin(); iteratorForSourceList != other.cend(); ++iteratorForSourceList) {
		push_back(*iteratorForSourceList);
	}
}

LinkedList::LinkedList(LinkedList&& other) noexcept
{
	head = other.head;
	len = other.len;
	other.head.next = &head;
	other.head.prev = &head;
	other.len = 0;
}

LinkedList::~LinkedList()
{
	clear();
}

LinkedList::iterator LinkedList::begin(){
	iterator result;
	result.currentNode = head.next;
	return result;
}

LinkedList::const_iterator LinkedList::begin() const
{
	const_iterator result;
	result.currentNode = head.next;
	return result;
}

LinkedList::const_iterator LinkedList::cbegin() const
{
	const_iterator result;
	result.currentNode = head.next;
	return result;
}

LinkedList::iterator LinkedList::end()
{
	iterator result;
	result.currentNode = &head;
	return result;
}

LinkedList::const_iterator LinkedList::end() const
{
	const_iterator result;
	result.currentNode = head.next->prev;
	return result;
}

LinkedList::const_iterator LinkedList::cend() const
{
	const_iterator result;
	result.currentNode = head.next->prev;
	return result;
}

int LinkedList::size() const
{
	return len;
}

bool LinkedList::empty() const
{
	return len == 0;
}

value_type& LinkedList::front()
{
	if (head.next != &head) {
		return head.next->value;
	}
	else {
		throw("trying to access to empty list");
	}
}

const value_type& LinkedList::front() const
{
	if (head.next != &head) {
		return head.next->value;
	}
	else {
		throw("trying to access to empty list");
	}
}

value_type& LinkedList::back()
{
	if (head.prev != &head) {
		return head.prev->value;
	}
	else {
		throw("trying to access to empty list");
	}
}

const value_type& LinkedList::back() const
{
	if (head.prev != &head) {
		return head.prev->value;
	}
	else {
		throw("trying to access to empty list");
	}
}

LinkedList::iterator LinkedList::erase(iterator position)
{
	if (position != end()) {
		--len;
		Node* toDeleteNode = position.currentNode;
		iterator front;
		iterator back;
		++position;
		back = position;
		----position;
		front = position;
		back.currentNode->prev = front.currentNode;
		front.currentNode->next = back.currentNode;
		delete toDeleteNode;
		return back != end() ? back : front;
	}
	else {
		throw("erase end Node");
	}
}

LinkedList::iterator LinkedList::erase(iterator begin, iterator end)
{
	auto iterator = begin;
	while (iterator != end) {
		auto toDelete = iterator++;
		erase(toDelete);
	}
	return end;
}

int LinkedList::remove(const value_type& value)
{
	int count = 0;
	for (iterator toDelete = begin(); toDelete != end(); ++toDelete) {
		if (*toDelete == value) {
			++count;
			erase(toDelete);
		}
	}
	return count;
}

void LinkedList::clear()
{
	while (!empty()) {
		pop_front();
	}
}

void LinkedList::pop_back()
{
	if (!empty()) {
		--len;
		Node* toDelete = head.prev;
		head.prev = head.prev->prev;
		head.prev->next = &head;
		delete toDelete;
	}
}

void LinkedList::pop_front()
{
	if (!empty()) {
		--len;
		Node* toDelete = head.next;
		head.next = head.next->next;
		head.next->prev = &head;
		delete toDelete;
	}
}

void LinkedList::push_back(const value_type& value)
{
	Node* newNode = new Node(value);
	newNode->prev = head.prev;
	newNode->next = &head;
	head.prev->next = newNode;
	head.prev = newNode;
	++len;
}

void LinkedList::push_front(const value_type& value)
{
	Node* newNode = new Node(value);
	newNode->next = head.next;
	newNode->prev = &head;
	head.next->prev = newNode;
	head.next = newNode;
	++len;
}

LinkedList::iterator LinkedList::insert(iterator before, const value_type& value)
{
	iterator after = --before;
	++before;
	Node* newNode = new Node(after.currentNode, before.currentNode, value);
	after.currentNode->next = newNode;
	before.currentNode->prev = newNode;
	++len;
	return before;
}

LinkedList& LinkedList::operator+=(const LinkedList& other)
{
	for (const_iterator toAdd = other.cbegin(); toAdd != other.cend(); ++toAdd) {
		push_back(*toAdd);
	}
	return *this;
}

bool operator!=(const LinkedList& left, const LinkedList& right)
{
	LinkedList::const_iterator first = left.cbegin();
	LinkedList::const_iterator second = right.cbegin();
	while (true) {
		if (first == left.cend() && second != right.cend() ||
			first != left.cend() && second == right.cend()) {
			return false;
		}
		if (first != left.cend() && second == right.cend()) {
			return true;
		}
		if (*first == *second) {
			++first;
			++second;
		}
		else {
			return false;
		}
	}
}

bool operator==(const LinkedList& left, const LinkedList& right)
{
	return !(left != right);
}
