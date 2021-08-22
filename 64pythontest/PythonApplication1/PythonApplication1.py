class Dog():
    """新建model类"""
    def __init__(self, name, age):
        """初始化属性name和age"""
        self.name = name
        self.age = age
    def sit(self):
        """模拟小狗被命令时蹲下"""
        print(self.name.title() + " is now sitting.")
    def roll_over(self):
        """模拟小狗被命令时打滚"""
        print(self.name.title() + " rolled over!")
    def test_method(self):
        '''测试方法'''
        return "ok"

my_dog = Dog('willie', 6)
my_dog.sit()
my_dog.roll_over()
data1 = my_dog.test_method()

print("end")