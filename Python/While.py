secret_number = 9
guess_count = 0
guess_limit = 3
while guess_count<guess_limit:
    if int(input('Guess a number '))==secret_number:
        print('You Win!')
        break
    guess_count+=1
print('End')