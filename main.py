from container.linked_list import LinkedList

import transport.bus
import transport.truck
import transport.car
import transport.decorators

from dataflow.io import IO


if __name__ == '__main__':

    container = LinkedList()
    io = IO(container, 'in', 'out')
    io.read()
    io.write()

    container.clean()

    print('Finished')
