using System;


interface IPayment
{
    void Pay(decimal amount);
}


class CardPayment : IPayment
{
    public void Pay(decimal amount)
    {
        Console.WriteLine($"Карта: оплатить {amount} рублей");
    }
}


class PayPal : IPayment
{
    public void Pay(decimal amount)
    {
        Console.WriteLine($"PayPal: оплатить {amount} рублей");
    }
}


class Crypto : IPayment
{
    public void Pay(decimal amount)
    {
        Console.WriteLine($"Криптовалюта: оплатить {amount} рублей");
    }
}


class PaymentProcessor
{
    public void MakePayment(IPayment method, decimal amount)
    {
        method.Pay(amount);
    }
}

class Program
{
    static void Main()
    {
        var processor = new PaymentProcessor();

        IPayment card = new CardPayment();
        IPayment paypal = new PayPal();
        IPayment crypto = new Crypto();

        
        processor.MakePayment(card, 100);
        processor.MakePayment(paypal, 200);
        processor.MakePayment(crypto, 300);
    }
}
