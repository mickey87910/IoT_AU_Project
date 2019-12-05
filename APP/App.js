import React from 'react';
import { Text, View,StyleSheet} from 'react-native';
import { createAppContainer } from 'react-navigation';
import { createBottomTabNavigator } from 'react-navigation-tabs';
import IconFA from 'react-native-vector-icons/FontAwesome';
import IconMCI from 'react-native-vector-icons/MaterialCommunityIcons';
import {Grid,Row,Col} from 'react-native-easy-grid';
class HomeScreen extends React.Component {
  render() {
    return (
      <View style={{ flex: 1}}>
        <Grid>
          <Row size={20}>
            <Col style={styles.top}>
              <IconFA name="thermometer-3" size={48} color="red">溫度</IconFA>
            </Col>
            <Col style={styles.top}>
              <IconMCI name="water-percent" size={48} color="blue">濕度</IconMCI>
            </Col>
          </Row>
          <Row size={15} >
            <Col>
              <Text style={styles.text}>30</Text>
            </Col>
            <Col>
              <Text style={styles.text}>80</Text>
            </Col>
          </Row>
          <Row size={65} style={styles.content}>
            <Text>123</Text>
          </Row>
        </Grid>
      </View>
    );
  }
}

class DatabaseScreen extends React.Component {
  render() {
    return (
      <View style={{ flex: 1, justifyContent: 'center', alignItems: 'center' }}>
        <Text>歷史資料庫位置</Text>
      </View>
    );
  }
}

const TabNavigator = createBottomTabNavigator({
  主頁面: {
    screen:HomeScreen,
    navigationOptions:{
      tabBarIcon : ({tintColor}) =>(
        <IconFA name="home" color={tintColor} size={32}></IconFA>
      )
    },
  },
  歷史資料庫: { 
    screen:DatabaseScreen,
    navigationOptions:{
      tabBarIcon:({tintColor}) =>(
        <IconFA name="database" color={tintColor} size={32}></IconFA>
      )
    }
  }
});
const styles = StyleSheet.create({
  top:{
    justifyContent:'flex-end',
    alignItems:'center',
  },
  text:{
    textAlign:'center',
    fontSize:64,
  },
  content:{
    justifyContent:'center',
    alignItems:'center',
  },
});
export default createAppContainer(TabNavigator);