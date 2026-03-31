public class BankAccount
{
   
    private decimal balance;

  
    public decimal Balance
    {
        get { return balance; }
    }

  
    public void Deposit(decimal amount)
    {
        if (amount <= 0)
        {
            throw new ArgumentException("Сумма пополнения должна быть положительной.");
        }
        balance += amount;
    }

    
    public void Withdraw(decimal amount)
    {
        if (amount <= 0)
        {
            throw new ArgumentException("Сумма снятия должна быть положительной.");
        }
        if (amount > balance)
        {
            throw new InvalidOperationException("Недостаточно средств для снятия.");
        }
        balance -= amount;
    }
}
