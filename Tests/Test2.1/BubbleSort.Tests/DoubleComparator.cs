﻿using System.Collections.Generic;
using static System.Math;

namespace BubbleSort.Tests
{
    /// <summary>
    /// Compares double numbers
    /// </summary>
    public class DoubleComparator : IComparer<double>
    {
        /// <summary>
        /// Compares double numbers
        /// </summary>
        /// <param name="first"> first number </param>
        /// <param name="second"> second number </param>
        /// <returns> difference between numbers </returns>
        public int Compare(double first, double second) => (int)(first - second);
    }
}
