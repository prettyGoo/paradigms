from container.linked_list import LinkedList
from container.decorators import SortDecorator

import transport.bus
import transport.truck
import transport.car
import transport.decorators

from dataflow.io import IO


if __name__ == '__main__':

    container = LinkedList()
    SortDecorator(container)

    io = IO(container, 'in', 'out')

    io.read()
    io.source.sort()
    io.write()

    container.clean()

    print('Finished')
