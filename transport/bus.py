from .abstract_transport import AbstractTransport


class Bus(AbstractTransport):
    id = 0

    def __init__(self, *args):
        params = args[0]

        self.capacity = params[0]
        super().__init__(params[1])

    def abstractionize(self):
        pass
