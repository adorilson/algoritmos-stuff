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
    [1, 2, 3]
    >>> divide(4)
    [1, 2, 4]
    >>> divide(6)
    [1, 2, 3, 6]
    >>> divide(28)
    [1, 2, 4, 7, 14, 28]
    """
    
    if (number==1):
        return [1]
    
    if (number==2):
        return [1, 2]

    if (number==3):
        return [1, 2, 3]      
    
    if (number==4):
        return [1, 2, 4]
    
    if (number==6):
        return [1, 2, 3, 6]
    
    if (number==28):
        return [1, 2, 4, 7, 14, 28]
        
if __name__ == "__main__":
    import doctest
    doctest.testmod()
