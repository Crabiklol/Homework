<Window x:Class="AuthModule.MainWindow"
        xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
        xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
        Title="Авторизация" Height="500" Width="400"
        MinWidth="320" MinHeight="420"
        Background="#121218"
        WindowStartupLocation="CenterScreen"
        ResizeMode="CanResize">

    <Window.Resources>
        <!-- Стиль для полей ввода (тёмный, минималистичный) -->
        <Style x:Key="InputStyle" TargetType="Control">
            <Setter Property="Background" Value="#2A2A35"/>
            <Setter Property="Foreground" Value="White"/>
            <Setter Property="BorderBrush" Value="#444455"/>
            <Setter Property="BorderThickness" Value="1"/>
            <Setter Property="Padding" Value="10,8"/>
            <Setter Property="Margin" Value="0,6,0,10"/>
            <Setter Property="FontSize" Value="14"/>
        </Style>

        <!-- Стиль кнопки с синим акцентом и скруглёнными углами -->
        <Style x:Key="AccentButton" TargetType="Button">
            <Setter Property="Background" Value="#3B82F6"/>
            <Setter Property="Foreground" Value="White"/>
            <Setter Property="FontWeight" Value="SemiBold"/>
            <Setter Property="FontSize" Value="14"/>
            <Setter Property="Cursor" Value="Hand"/>
            <Setter Property="Margin" Value="0,10,0,0"/>
            <Setter Property="Template">
                <Setter.Value>
                    <ControlTemplate TargetType="Button">
                        <Border Background="{TemplateBinding Background}" CornerRadius="8" Padding="12,10">
                            <ContentPresenter HorizontalAlignment="Center" VerticalAlignment="Center"/>
                        </Border>
                        <ControlTemplate.Triggers>
                            <Trigger Property="IsMouseOver" Value="True">
                                <Setter Property="Background" Value="#2563EB"/>
                            </Trigger>
                        </ControlTemplate.Triggers>
                    </ControlTemplate>
                </Setter.Value>
            </Setter>
        </Style>
    </Window.Resources>

    <TabControl Background="Transparent" BorderThickness="0" Margin="12">
        <!-- ВХОД -->
        <TabItem Header="Вход">
            <StackPanel Margin="15">
                <TextBlock Text="Логин / Email" Foreground="#9CA3AF" FontSize="13"/>
                <TextBox Name="LoginBox" Style="{StaticResource InputStyle}"/>
                <TextBlock Text="Пароль" Foreground="#9CA3AF" FontSize="13"/>
                <PasswordBox Name="PassBox" Style="{StaticResource InputStyle}"/>
                <Button Content="Войти" Click="Login_Click" Style="{StaticResource AccentButton}"/>
                <TextBlock Name="LoginMsg" Foreground="#F87171" Margin="0,12,0,0" TextAlignment="Center"/>
            </StackPanel>
        </TabItem>

        
        <TabItem Header="Регистрация">
            <StackPanel Margin="15">
                <TextBlock Text="Придумайте логин" Foreground="#9CA3AF" FontSize="13"/>
                <TextBox Name="RegLogin" Style="{StaticResource InputStyle}"/>
                <TextBlock Text="Придумайте пароль" Foreground="#9CA3AF" FontSize="13"/>
                <PasswordBox Name="RegPass" Style="{StaticResource InputStyle}"/>
                <TextBlock Text="Выберите роль" Foreground="#9CA3AF" FontSize="13"/>
                <ComboBox Name="RoleBox" Style="{StaticResource InputStyle}">
                    <ComboBoxItem Content="Пользователь"/>
                    <ComboBoxItem Content="Модератор"/>
                    <ComboBoxItem Content="Администратор"/>
                </ComboBox>
                <Button Content="Создать аккаунт" Click="Register_Click" Style="{StaticResource AccentButton}"/>
                <TextBlock Name="RegMsg" Foreground="#34D399" Margin="0,12,0,0" TextAlignment="Center"/>
            </StackPanel>
        </TabItem>

        
        <TabItem Header="Восстановление">
            <StackPanel Margin="15">
                <TextBlock Text="Введите email для сброса" Foreground="#9CA3AF" FontSize="13"/>
                <TextBox Name="RecoveryEmail" Style="{StaticResource InputStyle}"/>
                <Button Content="Отправить ссылку" Click="Recovery_Click" Style="{StaticResource AccentButton}"/>
                <TextBlock Name="RecoveryMsg" Foreground="#FBBF24" Margin="0,12,0,0" TextAlignment="Center"/>
            </StackPanel>
        </TabItem>

   
        <TabItem Header="Список">
            <DataGrid Name="UsersGrid" AutoGenerateColumns="True" Background="#FF000000" Foreground="White"
                      BorderBrush="#333344" GridLinesVisibility="Horizontal" Margin="5" IsReadOnly="True"
                      SelectionMode="Single" RowHeight="30"/>
        </TabItem>
    </TabControl>
</Window>
