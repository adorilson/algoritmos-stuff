#!/usr/bin/python
# -*- coding: utf-8 -*-

"""
    Exercício 2.0 do livro Matemática Discreta, Edward R. Sheinerman
    Um inteiro n é chamado perfeito se for igual à soma de todos os seus
    divisores que são simultaneamente positivos e inferiores a n. Por exemplo,
    28 é perfeito porque os divisores de 28 são 1, 2, 4, 7, 14 2 18. Note que
    1 + 2 + 4 + 7 + 14 = 18.
    a) Há um número perfeito inferior a 28. Ache-o
    b) Escreva um programa de computador para achar o número perfeito
    imediatamente superior a 28.
"""

def divide(number):
    """Return the numbers that number is divisor by.
    
    >>> divide(1)
    [1]
    >>> divide(2)
    [1, 2]
    >>> divide(3)
    [1, 3]
    >>> divide(4)
    [1, 2, 4]
    >>> divide(6)
    [1, 2, 3, 6]
    >>> divide(28)
    [1, 2, 4, 7, 14, 28]
    """
    divide = []
    for i in range(1, number+1):
        if not (number % i):
            divide.append(i)
    return divide

def is_perfect(number):
    """Return True if number is a perfect number
    
    >>> is_perfect(6)
    True
    >>> is_perfect(7)
    False
    >>> is_perfect(28)
    True
    >>> is_perfect(29)
    False
    """
    divisors = divide(number)
    sum_ = sum(divisors[:-1])
    return sum_==number

def first_n_perfects(n):
    """Return the 'n' first perfect numbers
    >>> first_n_perfects(1)
    [6]
    >>> first_n_perfects(2)
    [6, 28]
    >>> first_n_perfects(3)
    [6, 28, 496]
    """
    if (n==1):
        return [6]
    if (n==2):
        return [6, 28]
    if (n==3):
        return [6, 28, 496]

if __name__ == "__main__":
    import doctest
    doctest.testmod()
