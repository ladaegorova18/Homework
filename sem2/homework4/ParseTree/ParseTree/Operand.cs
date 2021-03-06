﻿using System;

namespace ParseTree
{
    /// <summary>
    /// Integer number as part of expression
    /// </summary>
    public class Operand : INode
    {
        /// <summary>
        /// Value - number in node
        /// </summary>
        public int Value { get; set; }

        /// <summary>
        /// constructor of node
        /// </summary>
        /// <param name="value"> number to put in 
        /// </param>
        public Operand(int value)
        {
            Value = value - '0';
        }

        /// <summary>
        /// Count value here means to return its value
        /// </summary>
        /// <returns> number itself </returns>
        public int Count() => Value;

        /// <summary>
        /// Operand as node of tree can not have children
        /// </summary>
        public Operation AddChild(char symbol, Operation current)
        {
            throw new NotImplementedException();
        }

        /// <summary>
        /// prints operand on console
        /// </summary>
        /// <param name="level"></param>
        public void Print(Action<int> tabulation, int level)
        {
            tabulation(level);
            Console.WriteLine(Count());
        }
    }
}
