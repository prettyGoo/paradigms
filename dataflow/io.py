import sys
import transport
import inspect
from abc import ABCMeta
package = transport


from pkgutil import walk_packages
submodules = []
for _, modname, _ in walk_packages(path=package.__path__, prefix=package.__name__+'.', onerror=lambda x: None):
    submodules.append(modname)


class IO(object):
    def __init__(self, source, stdin_path, stdout_path):
        self.stdin_path = stdin_path
        self.stdout_path = stdout_path
        self.source = source

    def read(self):
        with open(self.stdin_path, 'r') as f:
            self._prepare_entities_objects_list()
            raw_data = f.readline()

            while raw_data:
                data = raw_data.split(' ')
                self._create_entity_from_data(data)

                raw_data = f.readline()

    def write(self):
        with open(self.stdout_path, 'w') as f:
            active_node = self.source.head

            if active_node is None:
                return

            while active_node.next is not None:
                data = active_node.get_data()
                print(data, file=f)

                active_node = active_node.get_next()

    def _prepare_entities_objects_list(self):
        class_objects = []

        for submod in submodules:
            for name, class_obj in inspect.getmembers(sys.modules[submod]):
                if inspect.isclass(class_obj) and not inspect.isabstract(class_obj) \
                        and class_obj is not ABCMeta and not class_obj.__name__.endswith('Decorator'):
                    class_objects.append(class_obj)

        self.class_objects = class_objects

    def _create_entity_from_data(self, data):
        for entity in self.class_objects:
            if entity.id == int(data[0]):
                self.source.add(entity(4, 6))
                print(entity.__name__, data[0])