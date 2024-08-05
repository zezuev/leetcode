type Item = tuple[int, int]

class MinStack:
    
    def __init__(self):
        self.content: list[Item] = []

    def push(self, val: int):
        if not self.content:
            self.content.append((val, val))
        else:
            _, prev_min = self.content[-1]
            self.content.append((val, min(val, prev_min)))

    def pop(self):
        self.content.pop()

    def top(self) -> int:
        return self.content[-1][0]

    def get_min(self) -> int:
        return self.content[-1][1]