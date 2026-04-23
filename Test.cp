using ClassLibrary3;
using ikvm.lang;
using System;
using System.Runtime.InteropServices;
using System.Threading;
using System.Windows.Forms;
using Xceed.Wpf.Toolkit;

public class Class1
{
    // Loader bu ismi arıyor, ismin doğruluğundan emin ol
    [DllExport("NextHook", CallingConvention = CallingConvention.StdCall)]
    public static void NextHook()
    {
        // Oyunun ana thread'ini asla kilitlememek için yeni thread
        Thread t = new Thread(() =>
        {
            // Bazı oyunlarda mesaj kutusu en arkada kalır, 
            // ServiceNotification sayesinde her şeyin en üstünde çıkar.
            System.Windows.Forms.MessageBox.Show("sa kanka, Aetherix Software aktif!", "Aetherix",
                MessageBoxButtons.OK, MessageBoxIcon.Information,
                MessageBoxDefaultButton.Button1, MessageBoxOptions.ServiceNotification);
        });

        t.SetApartmentState(ApartmentState.STA);
        t.Start();
    }
}
