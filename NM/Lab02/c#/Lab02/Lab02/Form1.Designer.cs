namespace Lab02
{
    partial class Form1
    {
        /// <summary>
        /// Обязательная переменная конструктора.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Освободить все используемые ресурсы.
        /// </summary>
        /// <param name="disposing">истинно, если управляемый ресурс должен быть удален; иначе ложно.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Код, автоматически созданный конструктором форм Windows

        /// <summary>
        /// Требуемый метод для поддержки конструктора — не изменяйте 
        /// содержимое этого метода с помощью редактора кода.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.tableLayoutPanel1 = new System.Windows.Forms.TableLayoutPanel();
            this.zedGraphControl1 = new ZedGraph.ZedGraphControl();
            this.tableLayoutPanel2 = new System.Windows.Forms.TableLayoutPanel();
            this.btn_Newton1 = new System.Windows.Forms.Button();
            this.btn_Newton2 = new System.Windows.Forms.Button();
            this.btn_Newton3 = new System.Windows.Forms.Button();
            this.btn_NewtonFull = new System.Windows.Forms.Button();
            this.btn_Mashtab1 = new System.Windows.Forms.Button();
            this.btn_Mashtab2 = new System.Windows.Forms.Button();
            this.tableLayoutPanel3 = new System.Windows.Forms.TableLayoutPanel();
            this.tableLayoutPanel4 = new System.Windows.Forms.TableLayoutPanel();
            this.tableLayoutPanel5 = new System.Windows.Forms.TableLayoutPanel();
            this.label1 = new System.Windows.Forms.Label();
            this.txtA = new System.Windows.Forms.TextBox();
            this.tableLayoutPanel6 = new System.Windows.Forms.TableLayoutPanel();
            this.txtB = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.tableLayoutPanel7 = new System.Windows.Forms.TableLayoutPanel();
            this.txtN = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.btn_Error = new System.Windows.Forms.Button();
            this.txt_Error = new System.Windows.Forms.TextBox();
            this.tableLayoutPanel1.SuspendLayout();
            this.tableLayoutPanel2.SuspendLayout();
            this.tableLayoutPanel3.SuspendLayout();
            this.tableLayoutPanel4.SuspendLayout();
            this.tableLayoutPanel5.SuspendLayout();
            this.tableLayoutPanel6.SuspendLayout();
            this.tableLayoutPanel7.SuspendLayout();
            this.SuspendLayout();
            // 
            // tableLayoutPanel1
            // 
            this.tableLayoutPanel1.AutoSize = true;
            this.tableLayoutPanel1.ColumnCount = 2;
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 82.6087F));
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 17.3913F));
            this.tableLayoutPanel1.Controls.Add(this.zedGraphControl1, 0, 1);
            this.tableLayoutPanel1.Controls.Add(this.tableLayoutPanel2, 1, 1);
            this.tableLayoutPanel1.Controls.Add(this.tableLayoutPanel3, 0, 0);
            this.tableLayoutPanel1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.tableLayoutPanel1.Location = new System.Drawing.Point(0, 0);
            this.tableLayoutPanel1.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.tableLayoutPanel1.Name = "tableLayoutPanel1";
            this.tableLayoutPanel1.RowCount = 2;
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 9.156194F));
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 90.8438F));
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 31F));
            this.tableLayoutPanel1.Size = new System.Drawing.Size(962, 557);
            this.tableLayoutPanel1.TabIndex = 3;
            this.tableLayoutPanel1.TabStop = true;
            // 
            // zedGraphControl1
            // 
            this.zedGraphControl1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.zedGraphControl1.Location = new System.Drawing.Point(4, 55);
            this.zedGraphControl1.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.zedGraphControl1.Name = "zedGraphControl1";
            this.zedGraphControl1.ScrollGrace = 0D;
            this.zedGraphControl1.ScrollMaxX = 0D;
            this.zedGraphControl1.ScrollMaxY = 0D;
            this.zedGraphControl1.ScrollMaxY2 = 0D;
            this.zedGraphControl1.ScrollMinX = 0D;
            this.zedGraphControl1.ScrollMinY = 0D;
            this.zedGraphControl1.ScrollMinY2 = 0D;
            this.zedGraphControl1.Size = new System.Drawing.Size(786, 497);
            this.zedGraphControl1.TabIndex = 1;
            // 
            // tableLayoutPanel2
            // 
            this.tableLayoutPanel2.ColumnCount = 3;
            this.tableLayoutPanel2.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 10.73826F));
            this.tableLayoutPanel2.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 89.26174F));
            this.tableLayoutPanel2.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Absolute, 13F));
            this.tableLayoutPanel2.Controls.Add(this.btn_Newton1, 1, 0);
            this.tableLayoutPanel2.Controls.Add(this.btn_Newton2, 1, 1);
            this.tableLayoutPanel2.Controls.Add(this.btn_Newton3, 1, 2);
            this.tableLayoutPanel2.Controls.Add(this.btn_NewtonFull, 1, 3);
            this.tableLayoutPanel2.Controls.Add(this.btn_Mashtab1, 1, 4);
            this.tableLayoutPanel2.Controls.Add(this.btn_Mashtab2, 1, 5);
            this.tableLayoutPanel2.Controls.Add(this.btn_Error, 1, 6);
            this.tableLayoutPanel2.Controls.Add(this.txt_Error, 1, 7);
            this.tableLayoutPanel2.Dock = System.Windows.Forms.DockStyle.Top;
            this.tableLayoutPanel2.Location = new System.Drawing.Point(798, 55);
            this.tableLayoutPanel2.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.tableLayoutPanel2.Name = "tableLayoutPanel2";
            this.tableLayoutPanel2.RowCount = 9;
            this.tableLayoutPanel2.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 50.51546F));
            this.tableLayoutPanel2.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 49.48454F));
            this.tableLayoutPanel2.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 50F));
            this.tableLayoutPanel2.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 49F));
            this.tableLayoutPanel2.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 52F));
            this.tableLayoutPanel2.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 52F));
            this.tableLayoutPanel2.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 48F));
            this.tableLayoutPanel2.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 111F));
            this.tableLayoutPanel2.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 9F));
            this.tableLayoutPanel2.Size = new System.Drawing.Size(160, 469);
            this.tableLayoutPanel2.TabIndex = 2;
            // 
            // btn_Newton1
            // 
            this.btn_Newton1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.btn_Newton1.Location = new System.Drawing.Point(18, 3);
            this.btn_Newton1.Name = "btn_Newton1";
            this.btn_Newton1.Size = new System.Drawing.Size(125, 43);
            this.btn_Newton1.TabIndex = 5;
            this.btn_Newton1.Text = "Ньютон №1";
            this.btn_Newton1.UseVisualStyleBackColor = true;
            this.btn_Newton1.Click += new System.EventHandler(this.btn_Newton1_Click);
            // 
            // btn_Newton2
            // 
            this.btn_Newton2.Dock = System.Windows.Forms.DockStyle.Fill;
            this.btn_Newton2.Location = new System.Drawing.Point(18, 52);
            this.btn_Newton2.Name = "btn_Newton2";
            this.btn_Newton2.Size = new System.Drawing.Size(125, 42);
            this.btn_Newton2.TabIndex = 6;
            this.btn_Newton2.Text = "Ньютон №2";
            this.btn_Newton2.UseVisualStyleBackColor = true;
            this.btn_Newton2.Click += new System.EventHandler(this.btn_Newton2_Click);
            // 
            // btn_Newton3
            // 
            this.btn_Newton3.Dock = System.Windows.Forms.DockStyle.Fill;
            this.btn_Newton3.Location = new System.Drawing.Point(18, 100);
            this.btn_Newton3.Name = "btn_Newton3";
            this.btn_Newton3.Size = new System.Drawing.Size(125, 44);
            this.btn_Newton3.TabIndex = 7;
            this.btn_Newton3.Text = "Ньютон №3";
            this.btn_Newton3.UseVisualStyleBackColor = true;
            this.btn_Newton3.Click += new System.EventHandler(this.btn_Newton3_Click);
            // 
            // btn_NewtonFull
            // 
            this.btn_NewtonFull.Dock = System.Windows.Forms.DockStyle.Fill;
            this.btn_NewtonFull.Location = new System.Drawing.Point(18, 150);
            this.btn_NewtonFull.Name = "btn_NewtonFull";
            this.btn_NewtonFull.Size = new System.Drawing.Size(125, 43);
            this.btn_NewtonFull.TabIndex = 8;
            this.btn_NewtonFull.Text = "Ньютон Все";
            this.btn_NewtonFull.UseVisualStyleBackColor = true;
            this.btn_NewtonFull.Click += new System.EventHandler(this.btn_NewtonFull_Click);
            // 
            // btn_Mashtab1
            // 
            this.btn_Mashtab1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.btn_Mashtab1.Location = new System.Drawing.Point(18, 199);
            this.btn_Mashtab1.Name = "btn_Mashtab1";
            this.btn_Mashtab1.Size = new System.Drawing.Size(125, 46);
            this.btn_Mashtab1.TabIndex = 9;
            this.btn_Mashtab1.Text = "Масштаб №1";
            this.btn_Mashtab1.UseVisualStyleBackColor = true;
            this.btn_Mashtab1.Click += new System.EventHandler(this.btn_Mashtab1_Click);
            // 
            // btn_Mashtab2
            // 
            this.btn_Mashtab2.Dock = System.Windows.Forms.DockStyle.Fill;
            this.btn_Mashtab2.Location = new System.Drawing.Point(18, 251);
            this.btn_Mashtab2.Name = "btn_Mashtab2";
            this.btn_Mashtab2.Size = new System.Drawing.Size(125, 46);
            this.btn_Mashtab2.TabIndex = 10;
            this.btn_Mashtab2.Text = "Масштаб №2";
            this.btn_Mashtab2.UseVisualStyleBackColor = true;
            this.btn_Mashtab2.Click += new System.EventHandler(this.btn_Mashtab2_Click);
            // 
            // tableLayoutPanel3
            // 
            this.tableLayoutPanel3.ColumnCount = 2;
            this.tableLayoutPanel3.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 50F));
            this.tableLayoutPanel3.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 50F));
            this.tableLayoutPanel3.Controls.Add(this.tableLayoutPanel4, 0, 0);
            this.tableLayoutPanel3.Dock = System.Windows.Forms.DockStyle.Fill;
            this.tableLayoutPanel3.Location = new System.Drawing.Point(3, 3);
            this.tableLayoutPanel3.Name = "tableLayoutPanel3";
            this.tableLayoutPanel3.RowCount = 1;
            this.tableLayoutPanel3.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 50F));
            this.tableLayoutPanel3.Size = new System.Drawing.Size(788, 44);
            this.tableLayoutPanel3.TabIndex = 3;
            // 
            // tableLayoutPanel4
            // 
            this.tableLayoutPanel4.ColumnCount = 3;
            this.tableLayoutPanel4.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 50.97276F));
            this.tableLayoutPanel4.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 49.02724F));
            this.tableLayoutPanel4.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Absolute, 130F));
            this.tableLayoutPanel4.Controls.Add(this.tableLayoutPanel5, 0, 0);
            this.tableLayoutPanel4.Controls.Add(this.tableLayoutPanel6, 1, 0);
            this.tableLayoutPanel4.Controls.Add(this.tableLayoutPanel7, 2, 0);
            this.tableLayoutPanel4.Dock = System.Windows.Forms.DockStyle.Fill;
            this.tableLayoutPanel4.Location = new System.Drawing.Point(3, 3);
            this.tableLayoutPanel4.Name = "tableLayoutPanel4";
            this.tableLayoutPanel4.RowCount = 1;
            this.tableLayoutPanel4.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 50F));
            this.tableLayoutPanel4.Size = new System.Drawing.Size(388, 38);
            this.tableLayoutPanel4.TabIndex = 0;
            // 
            // tableLayoutPanel5
            // 
            this.tableLayoutPanel5.ColumnCount = 2;
            this.tableLayoutPanel5.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 38.4F));
            this.tableLayoutPanel5.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 61.6F));
            this.tableLayoutPanel5.Controls.Add(this.label1, 0, 0);
            this.tableLayoutPanel5.Controls.Add(this.txtA, 1, 0);
            this.tableLayoutPanel5.Location = new System.Drawing.Point(3, 3);
            this.tableLayoutPanel5.Name = "tableLayoutPanel5";
            this.tableLayoutPanel5.RowCount = 1;
            this.tableLayoutPanel5.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 50F));
            this.tableLayoutPanel5.Size = new System.Drawing.Size(125, 32);
            this.tableLayoutPanel5.TabIndex = 0;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.label1.Location = new System.Drawing.Point(3, 0);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(42, 32);
            this.label1.TabIndex = 0;
            this.label1.Text = "a:";
            this.label1.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // txtA
            // 
            this.txtA.Dock = System.Windows.Forms.DockStyle.Fill;
            this.txtA.Location = new System.Drawing.Point(51, 3);
            this.txtA.Name = "txtA";
            this.txtA.Size = new System.Drawing.Size(71, 26);
            this.txtA.TabIndex = 1;
            this.txtA.Text = "-1";
            this.txtA.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // tableLayoutPanel6
            // 
            this.tableLayoutPanel6.ColumnCount = 2;
            this.tableLayoutPanel6.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 38.33333F));
            this.tableLayoutPanel6.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 61.66667F));
            this.tableLayoutPanel6.Controls.Add(this.txtB, 0, 0);
            this.tableLayoutPanel6.Controls.Add(this.label2, 0, 0);
            this.tableLayoutPanel6.Location = new System.Drawing.Point(134, 3);
            this.tableLayoutPanel6.Name = "tableLayoutPanel6";
            this.tableLayoutPanel6.RowCount = 1;
            this.tableLayoutPanel6.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 50F));
            this.tableLayoutPanel6.Size = new System.Drawing.Size(120, 32);
            this.tableLayoutPanel6.TabIndex = 1;
            // 
            // txtB
            // 
            this.txtB.Dock = System.Windows.Forms.DockStyle.Fill;
            this.txtB.Location = new System.Drawing.Point(48, 3);
            this.txtB.Name = "txtB";
            this.txtB.Size = new System.Drawing.Size(69, 26);
            this.txtB.TabIndex = 2;
            this.txtB.Text = "3";
            this.txtB.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Dock = System.Windows.Forms.DockStyle.Fill;
            this.label2.Location = new System.Drawing.Point(3, 0);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(39, 32);
            this.label2.TabIndex = 1;
            this.label2.Text = "b:";
            this.label2.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // tableLayoutPanel7
            // 
            this.tableLayoutPanel7.ColumnCount = 2;
            this.tableLayoutPanel7.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 36F));
            this.tableLayoutPanel7.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 64F));
            this.tableLayoutPanel7.Controls.Add(this.txtN, 0, 0);
            this.tableLayoutPanel7.Controls.Add(this.label3, 0, 0);
            this.tableLayoutPanel7.Location = new System.Drawing.Point(260, 3);
            this.tableLayoutPanel7.Name = "tableLayoutPanel7";
            this.tableLayoutPanel7.RowCount = 1;
            this.tableLayoutPanel7.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 50F));
            this.tableLayoutPanel7.Size = new System.Drawing.Size(125, 32);
            this.tableLayoutPanel7.TabIndex = 2;
            // 
            // txtN
            // 
            this.txtN.Dock = System.Windows.Forms.DockStyle.Fill;
            this.txtN.Location = new System.Drawing.Point(48, 3);
            this.txtN.Name = "txtN";
            this.txtN.Size = new System.Drawing.Size(74, 26);
            this.txtN.TabIndex = 3;
            this.txtN.Text = "2";
            this.txtN.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Dock = System.Windows.Forms.DockStyle.Fill;
            this.label3.Location = new System.Drawing.Point(3, 0);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(39, 32);
            this.label3.TabIndex = 2;
            this.label3.Text = "n:";
            this.label3.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // btn_Error
            // 
            this.btn_Error.Dock = System.Windows.Forms.DockStyle.Fill;
            this.btn_Error.Location = new System.Drawing.Point(18, 303);
            this.btn_Error.Name = "btn_Error";
            this.btn_Error.Size = new System.Drawing.Size(125, 42);
            this.btn_Error.TabIndex = 11;
            this.btn_Error.Text = "Ошибка";
            this.btn_Error.UseVisualStyleBackColor = true;
            this.btn_Error.Click += new System.EventHandler(this.btn_Error_Click);
            // 
            // txt_Error
            // 
            this.txt_Error.Dock = System.Windows.Forms.DockStyle.Fill;
            this.txt_Error.Font = new System.Drawing.Font("Microsoft Sans Serif", 8F);
            this.txt_Error.Location = new System.Drawing.Point(18, 351);
            this.txt_Error.Multiline = true;
            this.txt_Error.Name = "txt_Error";
            this.txt_Error.Size = new System.Drawing.Size(125, 105);
            this.txt_Error.TabIndex = 12;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 20F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(962, 557);
            this.Controls.Add(this.tableLayoutPanel1);
            this.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.Name = "Form1";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Численные методы :: Лаб. раб. №2 :: Интерполяция полиномом Ньютона";
            this.tableLayoutPanel1.ResumeLayout(false);
            this.tableLayoutPanel2.ResumeLayout(false);
            this.tableLayoutPanel2.PerformLayout();
            this.tableLayoutPanel3.ResumeLayout(false);
            this.tableLayoutPanel4.ResumeLayout(false);
            this.tableLayoutPanel5.ResumeLayout(false);
            this.tableLayoutPanel5.PerformLayout();
            this.tableLayoutPanel6.ResumeLayout(false);
            this.tableLayoutPanel6.PerformLayout();
            this.tableLayoutPanel7.ResumeLayout(false);
            this.tableLayoutPanel7.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.TableLayoutPanel tableLayoutPanel1;
        private ZedGraph.ZedGraphControl zedGraphControl1;
        private System.Windows.Forms.TableLayoutPanel tableLayoutPanel2;
        private System.Windows.Forms.TableLayoutPanel tableLayoutPanel3;
        private System.Windows.Forms.TableLayoutPanel tableLayoutPanel4;
        private System.Windows.Forms.TableLayoutPanel tableLayoutPanel5;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox txtA;
        private System.Windows.Forms.TableLayoutPanel tableLayoutPanel6;
        private System.Windows.Forms.TextBox txtB;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TableLayoutPanel tableLayoutPanel7;
        private System.Windows.Forms.TextBox txtN;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Button btn_Newton1;
        private System.Windows.Forms.Button btn_Newton2;
        private System.Windows.Forms.Button btn_Newton3;
        private System.Windows.Forms.Button btn_NewtonFull;
        private System.Windows.Forms.Button btn_Mashtab1;
        private System.Windows.Forms.Button btn_Mashtab2;
        private System.Windows.Forms.Button btn_Error;
        private System.Windows.Forms.TextBox txt_Error;
    }
}

