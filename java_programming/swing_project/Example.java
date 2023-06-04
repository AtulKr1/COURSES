package swing_project;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.*;

public class Example implements ActionListener {
	JFrame f;
	JButton submit;
	JLabel output;
	
	Example()
	{
		f = new JFrame("Login Form");
		
		JLabel l1 = new JLabel("Full Name:");
		l1.setBounds(50, 20, 120, 80);
		f.add(l1);
		
		JTextField t1 = new JTextField();
		t1.setBounds(175, 45, 180, 30);
		f.add(t1);
		
		JLabel l2 = new JLabel("Contact:");
		l2.setBounds(50, 60, 120, 80);
		f.add(l2);
		
		JTextField t2 = new JTextField();
		t2.setBounds(175, 85, 180, 30);
		f.add(t2);
		
		JLabel l3 = new JLabel("Gender:");
		l3.setBounds(50, 100, 120, 80);
		f.add(l3);
		
		JRadioButton male = new JRadioButton("Male");
		male.setBounds(175, 130, 100, 20);
		f.add(male);
		
		JRadioButton female = new JRadioButton("Female");
		female.setBounds(275, 130, 100, 20);
		f.add(female);
		
		ButtonGroup bGroup = new ButtonGroup();
		bGroup.add(female);
		bGroup.add(male);
		
		JLabel l4 = new JLabel("Address:");
		l4.setBounds(50, 140, 120, 80);
		f.add(l4);
		
		JTextField t3 = new JTextField();
		t3.setBounds(175, 170, 180, 180);
		f.add(t3);
		
		submit = new JButton("Submit");
		submit.setBounds(213, 400, 100, 20);
		submit.addActionListener(this);
		f.add(submit);
		
		output = new JLabel("");
		output.setBounds(227, 450, 100, 20);
		f.add(output);
		
		f.setSize(500, 600);
        f.setLayout(null);
        f.setVisible(true);
	}
	
	public static void main(String[] args)
	{
		new Example();
	}

	@Override
	public void actionPerformed(ActionEvent e) {
		if(e.getSource() == submit) {
			output.setText("SUBMITTED");
		}
	}
}