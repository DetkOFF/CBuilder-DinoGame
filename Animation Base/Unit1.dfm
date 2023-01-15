object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'DinoGame'
  ClientHeight = 400
  ClientWidth = 500
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Image1: TImage
    Left = 0
    Top = 0
    Width = 500
    Height = 400
    OnClick = Image1Click
  end
  object FpsLabel: TLabel
    Left = 454
    Top = 0
    Width = 27
    Height = 16
    Caption = 'FPS:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object ScoreLabel: TLabel
    Left = 8
    Top = 0
    Width = 49
    Height = 16
    Caption = 'Score: 0'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Button1: TButton
    Left = 377
    Top = 24
    Width = 123
    Height = 57
    Caption = 'Restart'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    Visible = False
    OnClick = Button1Click
  end
  object CheckBox1: TCheckBox
    Left = 377
    Top = 1
    Width = 64
    Height = 17
    Caption = 'AutoJump'
    Checked = True
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    State = cbChecked
    TabOrder = 1
    OnClick = CheckBox1Click
  end
  object fpsTimer: TTimer
    OnTimer = fpsTimerTimer
    Left = 408
    Top = 304
  end
  object SceneTimer: TTimer
    Interval = 1
    OnTimer = SceneTimerTimer
    Left = 456
    Top = 304
  end
end
