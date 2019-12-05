import React from 'react';
import { Text, View,StyleSheet,StatusBar} from 'react-native';
import { createAppContainer} from 'react-navigation';
import { createBottomTabNavigator } from 'react-navigation-tabs';
import IconFA from 'react-native-vector-icons/FontAwesome';
import IconMCI from 'react-native-vector-icons/MaterialCommunityIcons';
import {Grid,Row,Col} from 'react-native-easy-grid';
class HomeScreen extends React.Component {
  constructor(props) {
    super(props)
    this.state = {
       temperature:"",
       humidity:"",
    }
}
  async getData(){
    fetch('http://120.108.112.87/animal_center/get_data.php', {
            method: 'post',
            header: {
                'Accept': 'application/json',
                'Contect-type': 'application/json',
            },
            body: JSON.stringify({

            })
        }).then((response) => response.json())
            .then((responseJson) => {
                var temp = responseJson.data[0].temperature;
                var humi = responseJson.data[0].humidity;
                console.log(temp)
                console.log(humi)
                this.setState({
                    temperature:temp,
                    humidity:humi,
                })
            })
            .catch((error) => {
                console.error(error);
            });
  };
  componentDidMount(){
    this.timer = setInterval(()=> this.getData(), 1000)
  }
  render() {
    return (
      <View style={{ flex: 1}}>
        {/* <Text style={styles.title}>亞洲大學動物中心APP</Text> */}
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
              <Text style={styles.text}>{this.state.temperature}℃</Text>
            </Col>
            <Col>
              <Text style={styles.text}>{this.state.humidity}%</Text>
            </Col>
          </Row>
          <Row size={5}>
            <Col style={styles.content}>
              <Text style={{fontSize:16}}>感測器狀態</Text>
              <Text style={{color:"gray",fontSize:16}}>●</Text>
              
            </Col>
            <Col style={styles.content}>
              <Text style={{fontSize:16}}>伺服器狀態</Text>
              <Text style={{color:"gray",fontSize:16}}>●</Text>
            </Col>
          </Row>
          <Row size={5} style={styles.content}>
            <Text>狀態：正常/異常</Text>
          </Row>
          <Row size={55}>
            <Text>剩餘的</Text>
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
        <Text>歷史資料庫頁面</Text>
      </View>
    );
  }
}

class SettingsScreen extends React.Component {
  render() {
    return (
      <View style={{ flex: 1, justifyContent: 'center', alignItems: 'center' }}>
        <Text>設定頁面</Text>
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
  },
  設定: {
    screen:SettingsScreen,
    navigationOptions:{
      tabBarIcon:({tintColor})=>(
        <IconMCI name="settings" color={tintColor} size={32}></IconMCI>
      )
    }
  },
});
const styles = StyleSheet.create({
  title:{
    textAlign:'center',
    fontSize:32,
  },
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
