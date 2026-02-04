using System;

class MatrixProcessor
{
    
    public static double FindGlobalMax(double[,] matrix)
    {
        int rows = matrix.GetLength(0);
        int cols = matrix.GetLength(1);

        double max = matrix[0, 0]; 

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (matrix[i, j] > max)
                {
                    max = matrix[i, j];
                }
            }
        }
        return max;
    }

    
    public static double FindMaxOfRowMinima(double[,] matrix)
    {
        int rows = matrix.GetLength(0);
        int cols = matrix.GetLength(1);

        double globalMax = double.NegativeInfinity; 

        for (int i = 0; i < rows; i++)
        {
            double rowMin = matrix[i, 0]; 

            
            for (int j = 1; j < cols; j++)
            {
                if (matrix[i, j] < rowMin)
                {
                    rowMin = matrix[i, j];
                }
            }

            
            if (rowMin > globalMax)
            {
                globalMax = rowMin;
            }
        }
        return globalMax;
    }
}


class Program
{
    static void Main()
    {
        // Пример матрицы 3x4
        double[,] matrix = {
            { 1.5, 3.2, 0.8, 4.1 },
            { 2.7, 1.1, 5.0, 0.9 },
            { 6.3, 2.4, 1.7, 3.8 }
        };

        
        double globalMax = MatrixProcessor.FindGlobalMax(matrix);
        Console.WriteLine($"Максимальный элемент в матрице: {globalMax}");

       
        double maxOfMinima = MatrixProcessor.FindMaxOfRowMinima(matrix);
        Console.WriteLine($"Максимум среди минимумов строк: {maxOfMinima}");
    }
}
