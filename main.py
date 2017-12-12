from container.linked_list import LinkedList
from container.decorators import SortDecorator

from transport.bus import Bus
import transport.truck
import transport.car
import transport.decorators

from dataflow.io import IO
from dataflow.decorators import WriteOnlyDecorator, MultiDecorator


if __name__ == '__main__':

    container = LinkedList()
    SortDecorator(container)

    io = IO(container, 'in', 'out')

    io.read()
    io.source.sort()
    io.write()

    WriteOnlyDecorator(io, Bus)
    io.write_only()

    MultiDecorator(io)
    io.multi()

    container.clean()

    print('Finished')
