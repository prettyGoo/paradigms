import unittest

from transport.bus import Bus
from transport.truck import Truck
from transport.car import Car

from container.linked_list import LinkedList
from dataflow.io import IO

class TestContainer(unittest.TestCase):

    b = Bus([1, 1])
    b1 = Bus([1, 1])

    t = Truck([2, 2])
    t1 = Truck([2, 2])

    c = Car([3, 3])
    c1 = Car([3, 3])

    l = LinkedList()
    l.add(b)
    l.add(t)
    l.add(c)
    l.add(t1)
    l.add(b1)
    l.add(c1)

    def test_add(self):
        length = 0
        active_node = self.l.head

        while active_node is not None:
            length += 1
            active_node = active_node.next

        self.assertEqual(length, 6)

    def test_clean(self):
        self.l.clean()
        self.assertEqual(self.l.head, None)


class TestIO(unittest.TestCase):
    container = LinkedList()
    io = IO(container, 'tests/test_in', 'tests/test_out')

    def test_read(self):
        self.io.read()

        length = 0
        active_node = self.container.head

        while active_node is not None:
            length += 1

            if length == 1:
                self.assertEqual(type(active_node.data), Car)
            elif length == 2:
                self.assertEqual(type(active_node.data), Truck)
            elif length == 3:
                self.assertEqual(type(active_node.data), Bus)

            active_node = active_node.next

        self.assertEqual(length, 3)

    def test_write(self):
        self.io.write()

        with open('tests/test_out', 'r') as f:
            data = f.readline()
            self.assertEquals(data, "Car: capacity = 1 id = 2 power = 5 \n")

            data = f.readline()
            self.assertEquals(data, "Truck: id = 1 power = 4 weight = 1 \n")

            data = f.readline()
            self.assertEquals(data, "Bus: id = 0 power = 1 weight = 1 \n")
