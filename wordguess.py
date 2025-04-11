# ====================================================================================
#                               Word Guess Game
# ====================================================================================
import random as r
def game():
    objects = [
        'chair', 'table', 'mirror', 'bottle', 'pencil',
        'phone', 'clock', 'window', 'wallet', 'laptop',
        'guitar', 'camera', 'helmet', 'remote', 'backpack',
        'lamp', 'charger', 'blanket', 'toaster', 'key'
    ]
    animals = [
        'tiger', 'elephant', 'monkey', 'rabbit', 'giraffe',
        'lion', 'zebra', 'kangaroo', 'panther', 'leopard',
        'dolphin', 'shark', 'camel', 'penguin', 'ostrich',
        'horse', 'wolf', 'fox', 'bear', 'koala'
    ]
    fruits = [
        'apple', 'banana', 'orange', 'grape', 'mango',
        'papaya', 'guava', 'peach', 'plum', 'kiwi',
        'melon', 'cherry', 'fig', 'pear', 'lychee',
        'lemon', 'lime', 'apricot', 'date', 'pomegranate'
    ]
    # Decide the level of the game
    try:
        level = int(input("Choose difficulty: \n 1. Easy \n 2. Medium \n 3. Hard \n >>>  "))
        if level == 1:
            attempt = 10
        elif level == 2:
            attempt = 6
        else:
            attempt = 5

        # choose a category
        category = int(input("Choose a Category : \n 1. Fruit \n 2. Object \n 3. Animal \n >>>  "))
        if category == 1:
            word_to_guess = r.choice(fruits)
        elif category == 2:
            word_to_guess = r.choice(objects)
        else:
            word_to_guess = r.choice(animals)
    except ValueError:
        print("Invalid input. Please enter a number .")
        return

    # define attempts
    guessed_word = ['_'] * len(word_to_guess)
    guessed_letters = []
    # Start the loop
    while attempt > 0:
        if ''.join(guessed_word) == word_to_guess:
            break
        print('\nCurrent Word: ' + ' '.join(guessed_word))

        # Take input
        guess = input('Guess a Letter: ').lower()

        # check if the entered word is valid
        if not guess.isalpha() or len(guess) != 1:
            print("Please enter a single valid letter.")
            continue
        # Check for repeat
        if guess in guessed_letters:
            print("You've already guessed that letter!")
            continue
        guessed_letters.append(guess)
        # Check if the guess is correct
        if guess in word_to_guess:
            for i in range(len(word_to_guess)):
                if guess == word_to_guess[i]:
                    guessed_word[i] = guess
                    print('\033[92mGreat Guess\033[0m')
        else:
            attempt-=1
            print('\033[91mWrong guess!\033[0m')
            print('Total attempt left: ', attempt)
    if '_' not in guessed_word:
        print('\n🎉 Congratulations!! You guessed the word: ' + word_to_guess)
    else:
        print('\n💔 You\'ve run out of attempts! The word was: ' + word_to_guess)

print('~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~')
print('                        W E L C O M E    T O W O R D   G U E S S     G A M E                          ')
print('~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~')

# call the func
game()

# replay the game for user
while True:
    try:
        replay = int(input("\nDo you want to play again? \n 1.Yes \n 2.No \n >>>>  "))
        if replay == 1:
            game()
        elif replay == 2:
            print("\t\t\t\tTTTTT  H   H  AAAAA  N   N  K   K    U   U \n\t\t\t\t  T    H   H  A   A  NN  N  K  K     U   U \n\t\t\t\t  T    HHHHH  AAAAA  N N N  K K      U   U \n\t\t\t\t  T    H   H  A   A  N  NN  KK       U   U \n\t\t\t\t  T    H   H  A   A  N   N  K  K     U   U \n\t\t\t\t  T    H   H  A   A  N   N  K   K    UUUUU \n")
            break
        else:
            print("Invalid input. Please enter 1 for Yes or 2 for No.")
    except ValueError:
        print("Invalid input. Please enter a number (1 or 2).")








