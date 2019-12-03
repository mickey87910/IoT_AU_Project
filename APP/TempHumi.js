import React from 'react';
import {View,Text,StyleSheet} from 'react-native';

export default class APP extends React.Component{
  render(){
    return (
      <View style={APP_style.A} >
        <Text>溫濕度</Text>
      </View>
    );
  }
}
const APP_style = StyleSheet.create({
    A:{
      flex : 1,
      fontSize : 10,
      justifyContent :'center',
      textAlign :'center',
      alignItems :'center',
    }
})