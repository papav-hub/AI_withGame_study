import queue
# 2019156037 최혜민

# 상태를 나타내는 클래스, f(n) 값을 저장한다.
class State:
    def __init__(self, board, moves=0):
        self.board = board
        self.moves = moves

    # i1과 i2를 교환하여서 새로운 상태를 반환한다.
    def get_new_board(self, i1, i2, moves):
        new_board = self.board[:]
        new_board[i1], new_board[i2] = new_board[i2], new_board[i1]
        return State(new_board, moves)

    # 자식 노드를 확장하여서 리스트에 저장하여서 반환한다.
    def expand(self, moves):
        result = []
        for i in range(n):
            for j in range(i, n):
                if(abs(self.board[i]-self.board[j])==abs(i-j)): # 대각선이 겹치는 부분 찾기
                    if(i != (j-1) and (j-1) >= 0):
                        result.append(self.get_new_board(i, j-1, moves)) # 대각선으로 겹치는 부분 다른것과 바꾸기
        return result


    def f(self):
        return self.h() + self.g()


    # 휴리스틱 함수 값인 h(n)을 계산하여 반환한다.
    # 현재 대각선으로 겹치는 경우의 개수를 모두 더한다.
    def h(self):
        count = 0
        for i in range(n):
            for j in range(i+1, n):
                if(abs(self.board[i]-self.board[j])==abs(i-j)): # 대각선이 겹치는 개수
                    count += 1
        return count


    # 시작 노드로부터의 경로를 반환한다.
    def g(self):
        return self.moves


    # 상태와 상태를 비교하기 위하여 less than 연산자를 정의한다.
    def __lt__(self, other):
        return self.f() < other.f()

    # print
    def __str__(self):
        return "f(n)=" + str(self.f()) + "\n" + "h(n)=" + str(self.h()) + "\n" + "g(n)=" + str(self.g()) + "\n" + str(self.board[:]) + "\n"


    # 목표상태 정의
    def goal(self):
        result = True

        for i in range(n):
            for j in range(i, n):
                if(abs(self.board[i]-self.board[j])==abs(i-j)): # 대각선이 겹친다.
                    if(i!=j):
                        result = False


        return result

    # 정답 출력
    def RESULT(self):
        array = [[' ']*n for i in range(n)]
        for i in range(n):
            array[i][self.board[i]] = "Q"

        for i in range(n):
            print(array[i][:])



        



print("2019156037 최혜민")
n = int(input("N-Queen의 n을 입력 : "))

puzzle = [i for i in range(n)] # 초기상태 // 각 행에서 퀸이 있는 열의 번호 // 열이 겹칠 일은 없다. 대각선이 겹치는 경우만 제거한다.

open_queue = []
open_queue.append(State(puzzle))

closed_queue = []
moves = 0


while len(open_queue) != 0:
    current = open_queue.pop(0)
    print(current)


    if(current.goal() == True):
        print("탐색 성공")
        print("2019156037 최혜민 정답")
        current.RESULT()
        break

    moves = current.moves + 1
    closed_queue.append(current)
    for state in current.expand(moves):
        if (state in closed_queue) or (state in open_queue): # 이미 거처간 노드이면 버린다.
            continue
        else:
            open_queue.append(state) # open list 끝에 추가