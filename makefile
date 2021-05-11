all: bubble insertion selection strings nums

bubble: bubble.c
	gcc bubble.c -o bubble

insertion: insertion.c
	gcc insertion.c -o insertion

selection: selection.c
	gcc selection.c -o selection

strings: 讀入隨機英文字串.c
	gcc 讀入隨機英文字串.c -o strings

nums: 讀入隨機變數.c
	gcc 讀入隨機變數.c -o nums

clean:
	rm -f bubble insertion selection strings nums
