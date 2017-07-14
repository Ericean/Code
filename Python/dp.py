
# coding: utf-8
def enter(msg):
    global level
    level+=1
    print "   " * level + msg
def leave(msg):
    global level
    print "   " * level + msg
    level-=1
    print ""

def fibo(num):
    enter("entering funct fibo with num= "+str(num))
    if num ==0 or num== 1:
        leave("leaving funct fibo")
        return 1
    else:
        sumof= fibo(num-1)+ fibo(num-2)
        leave("leaving funct fibo")
        return sumof

       
def memo_fibo(num):
    enter("entering funct memo_fibo with num= "+str(num))
    global level
    if num in cache:
        print  "   " * level+ "saving computation here"
        level-=1
        return cache[num]
    elif num == 0 or num == 1:
        cache[num]= 1
        leave("leaving funct memo_fibo")
        return 1
    else:
        cache[num]= memo_fibo(num-1)+memo_fibo(num-2)
        leave("leaving funct memo_fibo")
        return cache[num]

def dp_fibo(num):
    global cache 
    cache = dict()
    for i in range(num):
       print memo_fibo(i)
        
    
level = 0   
# cache= dict() 
# for i in reversed(range(0, 5)):
#     memo_fibo(i)
dp_fibo(5)





