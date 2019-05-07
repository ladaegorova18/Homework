﻿using System;

namespace GUICalculator
{
    public class Counter
    {
        /// <summary>
        /// Counts result of operation with two numbers
        /// </summary>
        /// <param name="first"> first number </param>
        /// <param name="second"> second number </param>
        /// <param name="operation"> operation to do </param>
        /// <returns> result of expression </returns>
        public float Count(float first, float second, string operation) =>
        operation switch
        {
            "+" => first + second,
            "-" => first - second,
            "/" => Dividing(first, second),
            "*" => first * second,
            _ => throw new ArgumentException("Некорректная операция!")
        };

        private float Dividing(float first, float second)
        {
            if (second != 0)
            {
                return first / second;
            }
            throw new DivideByZeroException();
        }
    }
}