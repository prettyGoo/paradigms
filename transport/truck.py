from .abstract_transport import AbstractTransport


class Truck(AbstractTransport):
    id = 1

    def __init__(self, *args):
        params = args[0]

        self.weight = params[0]
        super().__init__(params[1])

    def abstractionize(self):
        pass
