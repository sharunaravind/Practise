import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.sql.*;

public class FormOne extends JDialog {
    private JTextField tfName;
    private JTextField tfEmail;
    private JTextField tfSalary;
    private JButton btnSave;
    private JPanel SavePanel;
    private JTextArea tfResult;
    private JTextField tfId;
    private JButton button1;
    private JButton button2;
    private JButton button3;
    private JButton btnShow;
    private JLabel LabelId;

    public FormOne(JFrame parent,Connection conn) {
        super(parent);
        setTitle("Form One-Create new user");
        setContentPane(SavePanel);
        setModal(true);
        setMinimumSize(new Dimension(800, 600));
        setLocationRelativeTo(parent);
        System.out.println("Adding action listener to btnSave");
        btnSave.addActionListener(new ActionListener() {
//            @Override
            public void actionPerformed(ActionEvent e) {
                System.out.println("button pressed");
                RegisterUser(conn);
            }
        });

        btnShow.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                System.out.println("show all button pressed");
                ShowAllUsers(conn);
            }
        });
        setVisible(true);
    }

    private void ShowAllUsers(Connection conn) {
        StringBuilder result = new StringBuilder();

        String selectQuery = "SELECT * FROM users";

        try (Statement stmt = conn.createStatement();
             ResultSet rs = stmt.executeQuery(selectQuery)) {
            result.append("ID\t\t")
                    .append("Name\t\t")
                    .append("Email\t\t\t")
                    .append("Salary\t\t")
                    .append("\n");
            while (rs.next()) {
                int id = rs.getInt("id");
                String name = rs.getString("name");
                String email = rs.getString("email");
                int salary = rs.getInt("salary");


                result.append(id)
                        .append("\t\t").append(name)
                        .append("\t\t").append(email)
                        .append("\t\t").append(salary)
                        .append("\n");
            }

            tfResult.setText(result.toString());
        } catch (SQLException e) {
            e.printStackTrace();
            tfResult.setText("Error retrieving users.");
        }

    }

    private void RegisterUser(Connection conn) {

        System.out.printf("Registering user %s\n", tfId.getText());
        int id;
        String name = tfName.getText();
        String email = tfEmail.getText();
        int salary;

        try {
            id = Integer.parseInt(tfId.getText());
            salary = Integer.parseInt(tfSalary.getText());
        } catch (NumberFormatException e) {
            JOptionPane.showMessageDialog(this, "Invalid ID or salary input. Enter numbers.", "Error", JOptionPane.ERROR_MESSAGE);
            return;
        }

        String insertQuery = "INSERT INTO users (id, name, email, salary) VALUES (?, ?, ?, ?)";

        try (PreparedStatement pstmt = conn.prepareStatement(insertQuery)) { // Use existing connection
            pstmt.setInt(1, id);
            pstmt.setString(2, name);
            pstmt.setString(3, email);
            pstmt.setInt(4, salary);
            pstmt.executeUpdate();

            JOptionPane.showMessageDialog(this, "User registered successfully!", "Success", JOptionPane.INFORMATION_MESSAGE);
        } catch (SQLException e) {
            e.printStackTrace();
            JOptionPane.showMessageDialog(this, "Database error: " + e.getMessage(), "Error", JOptionPane.ERROR_MESSAGE);
        }
    }

    public static void main(String[] args) {
        String url = "jdbc:mysql://localhost:3306/";
        String user = "root";
        String password = "";
        try (Connection conn = DriverManager.getConnection(url, user, password);
             Statement stmt = conn.createStatement()) {


            String dbName = "testDB1"; //database name dont forget to change this

            String createDB = "CREATE DATABASE IF NOT EXISTS " + dbName;
            stmt.executeUpdate(createDB);

            String useDB = "USE " + dbName;
            stmt.executeUpdate(useDB);

            String createTable = """
                CREATE TABLE IF NOT EXISTS users (
                    id INT PRIMARY KEY,
                    name VARCHAR(50) not NULL,
                    email VARCHAR(50),
                    salary INT NOT NULL
                );
            """;
            stmt.executeUpdate(createTable);

            System.out.println("Database and table created successfully.");
            FormOne newForm = new FormOne(null,conn);

        } catch (SQLException e) {
            e.printStackTrace();
        }
    }


}
