class Node(object):

    def __init__(self, data, next=None):
        self.data = data
        self.next = next

    def get_data(self):
        return self.data

    def set_data(self, newdata):
        self.data = newdata

    def get_next(self):
        return self.next

    def set_next(self, newnext=None):
        self.next = newnext
