import unittest

from transport.bus import Bus
from transport.truck import Truck

from container.linked_list import LinkedList


class TestContainer(unittest.TestCase):

    b = Bus([1, 1])
    b1 = Bus([1, 1])

    t = Truck([2, 2])
    t1 = Truck([2, 2])

    l = LinkedList()
    l.add(b)
    l.add(t)
    l.add(b1)
    l.add(t1)

    def test_add(self):
        length = 0
        active_node = self.l.head

        while active_node is not None:
            length += 1
            active_node = active_node.next

        self.assertEqual(length, 4)

    def test_clean(self):
        self.l.clean()
        self.assertEqual(self.l.head, None)