class Queue:
    """
    队列（queue）是只允许在一端进行插入操作，而在另一端进行删除操作的线性表。
    假设队列是q=（a1，a2，……，an），那么a1就是队头元素，而an是队尾元素。
    这样我们就可以删除时，总是从a1开始，而插入时，总是在队列最后。
    """
    def __init__(self):
        self.items = []

    def is_empty(self):
        return self.items == []

    def enqueue(self, item):
        """由队尾进队列"""
        self.items.insert(0, item)

    def dequeue(self):
        """出队列"""
        return self.items.pop()

    def size(self):
        return len(self.items)


if __name__ == "__main__":
    q = Queue()
    q.enqueue("hello")
    q.enqueue("world")
    q.enqueue("10")
    print(q.size(), q.dequeue(), q.dequeue(), q.is_empty(), q.dequeue(), q.is_empty())

