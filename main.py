from abc import ABCMeta
import sys, inspect

from container.linked_list import LinkedList
from transport.bus import Bus
from transport.truck import Truck
import transport.decorators


import transport
from dataflow.io import IO


package = transport

from pkgutil import walk_packages
submodules = []
for _, modname, _ in walk_packages(path=package.__path__, prefix=package.__name__+'.', onerror=lambda x: None):
    submodules.append(modname)


container = LinkedList()
# io = IO(container, 'in', 'out')


# print(sys.modules.keys())
# sys.exit(1)

with open('in', 'r') as f:
    while True:
        raw_data = f.readline().replace('\n', '')
        if raw_data:
            for submod in submodules:
                for name, class_obj in inspect.getmembers(sys.modules[submod]):
                    if inspect.isclass(class_obj) and not inspect.isabstract(class_obj) \
                            and class_obj is not ABCMeta and not class_obj.__name__.endswith('Decorator'):
                        if class_obj.id == int(raw_data):
                            container.add(globals()[name](4, 6))
                            print(name, raw_data)
        else:
            break


f.close()

with open('out', 'w') as f:

    active_node = container.head
    sys.exit(0) if active_node is None else None

    while active_node.next is not None:
        data = active_node.get_data()
        print(data, file=f)

        active_node = active_node.get_next()

f.close()