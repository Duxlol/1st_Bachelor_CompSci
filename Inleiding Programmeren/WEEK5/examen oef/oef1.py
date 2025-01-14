class Point:
    def __init__(self,x,y):
        self.x = x
        self.y = y
    def print(self):
        print(f"({self.x},{self.y})")
    def reflect_x(self):
        return Point(self.x,-self.y)
    def distance(self, other_point):
        return sqrt((self.x - other_point.x) ** 2 + (self.y - other_point.y) ** 2)
