   M S B A M L   `   `   `  ����B  >justfun, Version=1.0.0.0, Culture=neutral, PublicKeyToken=null!clr-namespace:justfunjustfun  5   	       justfun.MainWindow   5   	   W SPresentationCore, Version=6.0.2.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35\ XPresentationFramework, Version=6.0.2.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35e aSystem.Windows.Controls.Ribbon, Version=6.0.2.0, Culture=neutral, PublicKeyToken=b77a5c561934e089R NWindowsBase, Version=6.0.2.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35F 9http://schemas.microsoft.com/winfx/2006/xaml/presentation     5   	   R NSystem.Xaml, Version=6.0.2.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     5   	   @d2http://schemas.microsoft.com/expression/blend/2008     5   	   Jmc;http://schemas.openxmlformats.org/markup-compatibility/2006     5   	   'localclr-namespace:justfun     5   	     � Title$  
MainWindow��5   	   $	��500��6   $	��800��6)   .��5	      � ���#80ceff � RowDefinitions 5
   
   �� 5      $
��90px �6   �� 5      $��220px �6   �� 5      $��1* �6   .+�5   
   ��  �� Orientation$ 
Horizontal=�6   $��Center=�6.   .+�5      �� $��./Resources/image.png��6   65   5      � 5   
   $��1��6    � ColumnDefinitions 5      �� 5      $��1* �6#   �� 5      $��1* �6#   .+�5      �� $��20q�6   $��1��6%   .+�5      �� .+�5      �� $
��Name��6   �� 5      -   5         ��Name$ 	NameInput��5      5       �� 5"      .+�5#      �� $��Index��6   �� 5$      -   5        $ 
IndexInput��5$      5%      �� 5'      .+�5(      �� $��Grade��6   �� 5)      -   5        $ 
GradeInput��5)      5*      �� 5,      .+�5-      �� $��Comment��6   �� 5.      -   5        $ CommentInput��5.      5/      50      �� 52      $��1��6   .��53      �� -   5         ��Name$ LogViewerText��53      54      56      �� 59   
   $��2��6   $��10q�6"   .+�5<      �� $��0 0 0 10q�6   $ 
Horizontal=�6+   .+�5=      �� -   5        $��Add to list��5=      $��0 0 10 0q�6/   6A   �� 5>      -   5        $��Average��5>      $��0 0 10 0q�6+   6=   �� 5?      -   5        $��Remove��5?      $��0 0 10 0q�6*   6<   �� 5@      -	   5        $��Reset��5@      6)   5A      �� 5D      $ Vertical=�6   .+�5E      �� -
   5         ��Name$ listStudents��5E       �� SelectionMode$ Single=�61    �� View 5F      �� 5G      .P�5H      �� -   5        
NameColumn��$
��Name��5H   A   	 �� DisplayMemberBinding	 6O   �� *Name+�� 5I      -   5        IndexColumn��$��Index��5I   B   	 6Q   �� *Index+�� 5J      -   5        GradeColumn��$��Grade��5J   B   	 6Q   �� *Grade+�� 5K      -   5        PassedColumn��$��	Is Passed��5K   C   	 6V   �� *Passed+�� 5L      -   5        CommentColumn��$��Comment��5L   D   	 6U   �� *	Comment+5M      5O      � 5Q      $y�Hidden=�6    5R      �� 5S      ��6+   �� 
 �� ElementName$
 
NameColumn�� �� Path$ ActualWidth��� 5T      $��* �6+   �� 5U      $��10 �6+   .+�5W      � -   5         �Name$ helperField��5W   +   $��1��6   6+   5X      5Y      5Z      5[      5\      