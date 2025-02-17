import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.sql.*;

public class FormOne extends JDialog {
    private JTextField tfDate;
    private JTextField tfTotal;
    private JTextField tfSalary;
    private JButton btnSave;
    private JPanel SavePanel;
    private JTextArea tfResult;
    private JTextField tfOrderId;
    private JButton btnDelete;
    private JButton btnUpdate;
    private JButton btnSearch;
    private JButton btnShow;
    private JLabel LabelId;
    private JTextField tfProductId;
    private JTextField tfQuantity;

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
                SaveOrder(conn);
            }
        });

        btnShow.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                System.out.println("show all button pressed");
                ShowAllData(conn);
            }
        });

        btnDelete.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                DeleteOrder(conn);
            }
        });

        btnUpdate.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                updateOrder(conn);
            }
        });
       
        btnSearch.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                SearchOrder(conn);
            }
        });
        setVisible(true);
    }

    private void SearchOrder(Connection conn) {
        System.out.printf("Searching Orders for Date: %s\n", tfDate.getText());

        String order_date = tfDate.getText();

        String searchQuery = "SELECT order_id, order_date, total_amount FROM orders WHERE order_date = ?";

        try (PreparedStatement pstmt = conn.prepareStatement(searchQuery)) {
            pstmt.setString(1, order_date);
            ResultSet rs = pstmt.executeQuery();

            StringBuilder result = new StringBuilder("Orders on " + order_date + ":\n");

            boolean found = false;
            while (rs.next()) {
                found = true;
                result.append("Order ID: ").append(rs.getInt("order_id"))
                        .append(", Total Amount: ").append(rs.getFloat("total_amount"))
                        .append("\n");
            }

            if (found) {
                System.out.println(result);
                tfResult.setText(result.toString());
            } else {
                System.out.println("No orders found for this date.");
                tfResult.setText("No orders found for this date.");
            }

        } catch (SQLException e) {
            e.printStackTrace();
            System.out.println("Error searching orders - database error.");
        }
    }

    private void updateOrder(Connection conn) {
        System.out.printf("Updating Order: %s\n", tfOrderId.getText());

        int order_id;
        int total_amount;

        try {
            order_id = Integer.parseInt(tfOrderId.getText());
            total_amount = Integer.parseInt(tfTotal.getText());
        } catch (NumberFormatException e) {
            System.out.println("Error: Order ID and total amount must be numbers.");
            tfResult.setText("Error: Order ID and total amount must be numbers.");
            return;
        }

        String updateQuery = "UPDATE orders SET total_amount = ? WHERE order_id = ?";

        try (PreparedStatement pstmt = conn.prepareStatement(updateQuery)) {
            pstmt.setInt(1, total_amount);
            pstmt.setInt(2, order_id);
            int rowsAffected = pstmt.executeUpdate();

            if (rowsAffected > 0) {
                System.out.println("Order updated successfully.");
                tfResult.setText("Order updated successfully.");
            } else {
                System.out.println("Order ID not found.");
                tfResult.setText("Order ID not found.");
            }

        } catch (SQLException e) {
            e.printStackTrace();
            System.out.println("Error updating order - database error.");
        }
    }

    private void DeleteOrder(Connection conn) {
        System.out.printf("Deleting Order: %s\n", tfOrderId.getText());

        int order_id;
        try {
            order_id = Integer.parseInt(tfOrderId.getText());
        } catch (NumberFormatException e) {
            System.out.println("Error: Order ID must be a number.");
            tfResult.setText("Error: Order ID must be a number.");
            return;
        }

        String deleteOrderDetailsQuery = "DELETE FROM order_details WHERE order_id = ?";
        String deleteOrderQuery = "DELETE FROM orders WHERE order_id = ?";

        try (PreparedStatement pstmtDetails = conn.prepareStatement(deleteOrderDetailsQuery);
             PreparedStatement pstmtOrder = conn.prepareStatement(deleteOrderQuery)) {

            pstmtDetails.setInt(1, order_id);
            pstmtDetails.executeUpdate();

            pstmtOrder.setInt(1, order_id);
            int rowsAffected = pstmtOrder.executeUpdate();

            if (rowsAffected > 0) {
                System.out.println("Order deleted successfully.");
                tfResult.setText("Order deleted successfully.");
            } else {
                System.out.println("Order ID not found.");
                tfResult.setText("Order ID not found.");
            }

        } catch (SQLException e) {
            e.printStackTrace();
            System.out.println("Error deleting order - database error.");
        }
    }

    private void ShowAllData(Connection conn) {
        StringBuilder result = new StringBuilder();

        String selectQuery = "SELECT o.order_id,e.product_id,e.Quantity FROM `orders` o JOIN order_details e ON o.order_id=e.order_id";

        try (Statement stmt = conn.createStatement();
             ResultSet rs = stmt.executeQuery(selectQuery)) {
            result.append("ID\t\t")
                    .append("Product ID\t\t")
                    .append("Quantity\t\t\t")
                    .append("\n");
            while (rs.next()) {
                int id = rs.getInt("order_id");
                String name = rs.getString("product_id");
                String email = rs.getString("quantity");

                result.append(id)
                        .append("\t\t").append(name)
                        .append("\t\t").append(email)
                        .append("\n");
            }

            tfResult.setText(result.toString());
        } catch (SQLException e) {
            e.printStackTrace();
            tfResult.setText("Error retrieving users.");
        }

    }

    private void SaveOrder(Connection conn) {

        System.out.printf("Saving Order :%s\n", tfOrderId.getText());
        int order_id;
        String date = tfDate.getText();
        System.out.println(date);
        int total;
        int product_id;
        int quantity;

        try {
            order_id = Integer.parseInt(tfOrderId.getText());
            total = Integer.parseInt(tfTotal.getText());
            product_id = Integer.parseInt(tfProductId.getText());
            quantity = Integer.parseInt(tfQuantity.getText());
        } catch (NumberFormatException e) {
            System.out.println("Error gettings order_id and amount");
            tfResult.setText("Error gettings order_id and amount. Make sure they are numbers");
            return;
        }

        String insertQuery = "INSERT INTO orders(order_id,order_date,total_amount) VALUES (?,?,?);";

        try (PreparedStatement pstmt = conn.prepareStatement(insertQuery)) { 
            pstmt.setInt(1, order_id);
            pstmt.setString(2,tfDate.getText());
            pstmt.setInt(3, total);
            pstmt.executeUpdate();

            System.out.println("Saved successfully");
        } catch (SQLException e) {
            e.printStackTrace();
            System.out.println("Error registering user - dabatabase error 2");
        }
        String insertQuery2 = "INSERT INTO order_details(order_id,product_id,quantity) VALUES (?,?,?);";

        try (PreparedStatement pstmt1 = conn.prepareStatement(insertQuery2)) {
            pstmt1.setInt(1, order_id);
            pstmt1.setInt(2, product_id);
            pstmt1.setInt(3, quantity);
            pstmt1.executeUpdate();

            System.out.println("Saved successfully");
        } catch (SQLException e) {
            e.printStackTrace();
            System.out.println("Error registering user - dabatabase error 2");
        }
    }

    public static void main(String[] args) {
        String url = "jdbc:mysql://localhost:3306/";
        String user = "root";
        String password = "";
        try (Connection conn = DriverManager.getConnection(url, user, password);
             Statement stmt = conn.createStatement()) {


            String dbName = "ECDB"; //database name dont forget to change this

            String createDB = "CREATE DATABASE IF NOT EXISTS " + dbName;
            stmt.executeUpdate(createDB);

            String useDB = "USE " + dbName;
            stmt.executeUpdate(useDB);

            String createTable1 = """
                CREATE TABLE IF NOT EXISTS orders (
                    order_id INT PRIMARY KEY,
                    order_date date NOT NULL,
                    total_amount FLOAT not null
                );
            """;
            String createTable2 = """
                    CREATE TABLE IF NOT EXISTS order_details (
                    order_detail_id INT PRIMARY KEY AUTO_INCREMENT,
                    order_id INT,
                    product_id INT not null,
                    Quantity INT
                );
                    """;
            stmt.executeUpdate(createTable1);
            System.out.println("Database and table1 created successfully.");
            stmt.executeUpdate(createTable2);
            System.out.println("Database and table2 created successfully.");
            FormOne newForm = new FormOne(null,conn);

        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

}
