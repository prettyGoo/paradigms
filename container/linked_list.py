from abc import ABCMeta, abstractmethod

from .node import Node


class LinkedList(object):
    def __init__(self):
        self.head = None

    def add(self, item):
        active_node = Node(item)
        active_node.set_next(self.head)

        self.head = active_node

    def clean(self):
        self.head = None

    def _is_empty(self):
        return self.head is None

